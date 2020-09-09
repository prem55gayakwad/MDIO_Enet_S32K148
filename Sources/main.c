/*
 * Copyright (c) 2015 - 2016 , Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "pin_mux.h"
#include "ethernet1.h"
#include "phy_cfg.h"
#include "phy.h"
#include "phy_tja110x.h"
#include "dmaController1.h"
#include "clockMan1.h"

volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

/* This example is setup to work by default with EVB. To use it with other boards
   please comment the following line
*/

#define EVB

#ifdef EVB
	#define GPIO_PORT	PTE
	#define PCC_CLOCK	PCC_PORTE_CLOCK
	#define LED_RED		21U
	#define LED_GREEN	22U
	#define LED_BLUE	23U
#else
	#define GPIO_PORT	PTC
	#define PCC_CLOCK	PCC_PORTC_CLOCK
	#define LED_RED		0U
	#define LED_GREEN	1U
	#define LED_BLUE	2U	// not sure if this is correct!
#endif

typedef struct {
	uint8_t destAddr[6];
	uint8_t srcAddr[6];
	uint16_t etherType;
	uint8_t payload[1500];
} mac_frame_t;

mac_frame_t TxFrame;	// get one buffer on heap
mac_frame_t *RxFrame;	// buffer data comes from ENET driver
bool PhyLinkUp;



uint8_t ethMacAddrBroadcast[6] = {0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU};
uint8_t ethMacAddrTgt[6] = {0x11U, 0x22U, 0x33U, 0x77U, 0x88U, 0x99U};



void link_up(uint8_t phy)
{
	// this demo only supports 1 external phy (TJA1100 or TJA1101)
	if (phy == 0)
		PhyLinkUp = true;
}


void link_down(uint8_t phy)
{
	// this demo only supports 1 external phy (TJA1100 or TJA1101)
	if (phy == 0)
		PhyLinkUp = false;
}



void delay(volatile int cycles)
{
    /* Delay function - do nothing for a number of cycles */
    while(cycles--);
}

void copyBuff(uint8_t *dest, uint8_t *src, uint32_t len)
{
	uint32_t i;

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
}

void rx_callback(uint8_t instance, enet_event_t event)
{
	(void)instance;

	if (event == ENET_RX_EVENT)
	{
		enet_buffer_t buff;
		status_t status;

		status = ENET_DRV_ReadFrame(INST_ETHERNET1, &buff, NULL);
		if (status == STATUS_SUCCESS)
		{
			mac_frame_t *frame;

			frame = (mac_frame_t *) buff.data;

			/* You can process the payload here */
			(void)frame->payload;

			/* We successfully received a frame -> turn on LED 2 */
			PINS_DRV_ClearPins(GPIO_PORT, (1 << LED_RED));
			PINS_DRV_SetPins(GPIO_PORT, (1 << LED_GREEN));

			ENET_DRV_ProvideRxBuff(INST_ETHERNET1, &buff);
		}
	}
}

/*!
 \brief The main function for the project.
 \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
 */
int main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
#ifdef PEX_RTOS_INIT
  PEX_RTOS_INIT(); /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
#endif
  /*** End of Processor Expert internal initialization.                    ***/

  /* Initialize and configure clocks
   * 	-	see clock manager component for details
   */
  CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
                 g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
  CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

  /* Output Buffer Enable for ENET MII clock in internal loopback mode */
  SIM->MISCTRL0 |= SIM_MISCTRL0_RMII_CLK_SEL(1);

  /* Initialize pins
   *	-	See PinSettings component for more info
   */
  PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

  /* Turn off LED 1 and LED 2 */
  PINS_DRV_ClearPins(GPIO_PORT, (1 << LED_RED));
  PINS_DRV_ClearPins(GPIO_PORT, (1 << LED_GREEN));

  /* Disable MPU */
  MPU->CESR = 0x00815200;

  /* Initialize ENET instance */
  ENET_DRV_Init(INST_ETHERNET1, &ethernet1_State, &ethernet1_InitConfig0, &ethernet1_buffConfig0, ethernet1_MacAddr);

  enet_buffer_t txBuff, rxBuff;
  enet_tx_enh_info_t txInfo;
  enet_rx_enh_info_t rxInfo;
  uint8_t i;


  TxFrame.etherType = 0x0800;	// EtherType LLC
  for (i = 0; i < 64U; i++)
  {
	  TxFrame.payload[i] = i;
  }

  copyBuff(TxFrame.destAddr, ethMacAddrTgt, 6U);
  copyBuff(TxFrame.srcAddr, ethernet1_MacAddr, 6U);

  txBuff.data = (uint8_t *)&TxFrame;
  /* Length == 12 bytes MAC addresses + 2 bytes length + 64 bytes payload */
  txBuff.length = 64U + 14;

  /* MDIO simple test example */
  ENET_DRV_EnableMDIO(INST_ETHERNET1, false);

  status_t state;

  state = PHY_FrameworkInit(phyConfig, phyDrivers);
  state = PHY_Init(0);

  bool linkStatus;


  /* Infinite loop:
   * 	- Send frames
   * 	- Verify LinkStatus
   */


  while (1)
  {

	  state = PHY_GetLinkStatus(0, &linkStatus);
	  if (linkStatus)
	  {
		  PINS_DRV_ClearPins(GPIO_PORT, (1 << LED_RED));
		  PINS_DRV_SetPins(GPIO_PORT, (1 << LED_GREEN));
	  }
	  else
	  {
	      PINS_DRV_ClearPins(GPIO_PORT, (1 << LED_GREEN));
	      PINS_DRV_SetPins(GPIO_PORT, (1 << LED_RED));
	  }

	  /* We are about to send a frame */
	  if (linkStatus)
	  {
		  PINS_DRV_SetPins(GPIO_PORT, (1 << LED_BLUE));
		  state = ENET_DRV_SendFrame(INST_ETHERNET1, &txBuff);

		  if (state != STATUS_SUCCESS)
		  {
			  PINS_DRV_SetPins(GPIO_PORT, (1 << LED_RED));
			  PINS_DRV_ClearPins(GPIO_PORT, (1 << LED_GREEN));
		  }

		  // verify transmission state

		  state = ENET_DRV_GetTransmitStatus(INST_ETHERNET1, &txBuff, &txInfo);

		  // verify if something to read
		  state = ENET_DRV_ReadFrame(INST_ETHERNET1, &rxBuff, &rxInfo);

		  if (state==STATUS_SUCCESS)
		  {
			  /*
			   * do something with received data here
			   */

			  RxFrame = (mac_frame_t *)rxBuff.data;

			  // pull internal data-buffer back to driver pool
			  ENET_DRV_ProvideRxBuff(INST_ETHERNET1, &rxBuff);
		  }
	  }
      delay(100000);	// 1000 ms
      PINS_DRV_ClearPins(GPIO_PORT, (1 << LED_BLUE));
      delay(480000);	// 1000 ms
  }
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;) {
    if(exit_code != 0) {
      break;
    }
  }
  return exit_code;
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.1 [05.21]
 **     for the Freescale S32K series of microcontrollers.
 **
 ** ###################################################################
 */

