/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : ethernet1.c
**     Project     : MDIO_Enet_S32K148
**     Processor   : S32K148_144
**     Component   : enet
**     Version     : Component SDK_S32K14x_09, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32K14x_09
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-09-08, 16:32, # CodeGen: 0
**
**     Copyright 1997 - 2015 Freescale Semiconductor, Inc.
**     Copyright 2016-2017 NXP
**     All Rights Reserved.
**     
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file ethernet1.c
** @version 01.00
*/
/*!
**  @addtogroup ethernet1_module ethernet1 module documentation
**  @{
*/

#include "ethernet1.h"

/*! @brief Number of receive buffer descriptors */
#define ENET_RXBD_NUM0 (5U)
/*! @brief Number of transmit buffer descriptors */
#define ENET_TXBD_NUM0 (5U)

enet_state_t ethernet1_State;

/*! @brief The MAC address of the module */
uint8_t ethernet1_MacAddr[6] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66};

/*! @brief Module configuration structures */
const enet_config_t ethernet1_InitConfig0 =
{
    .interrupts = 0,
    .maxFrameLen = 1518U,
    .miiMode = ENET_RMII_MODE,
    .miiSpeed = ENET_MII_SPEED_100M,
    .miiDuplex = ENET_MII_FULL_DUPLEX,
    .rxAccelerConfig = 0,
    .txAccelerConfig = 0,
    .rxConfig = 0,
    .txConfig = 0,
    .callback = NULL
};

/*! @brief Receive buffer descriptors */
ALIGNED(FEATURE_ENET_BUFFDESCR_ALIGNMENT) enet_buffer_descriptor_t ethernet1_rxBuffDescrip0[ENET_RXBD_NUM0];
/*! @brief Transmit buffer descriptors */
ALIGNED(FEATURE_ENET_BUFFDESCR_ALIGNMENT) enet_buffer_descriptor_t ethernet1_txBuffDescrip0[ENET_TXBD_NUM0];

/*! @brief Receive data buffers */
ALIGNED(FEATURE_ENET_BUFF_ALIGNMENT) uint8_t ethernet1_rxDataBuff0[ENET_RXBD_NUM0 * ENET_BUFF_ALIGN(1518U)];

/*! @brief Buffer configuration structures */
enet_buffer_config_t ethernet1_buffConfig0 =
{
    ENET_RXBD_NUM0,
    ENET_TXBD_NUM0,
    &ethernet1_rxBuffDescrip0[0],
    &ethernet1_txBuffDescrip0[0],
    &ethernet1_rxDataBuff0[0]
};
/* END ethernet1. */

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


