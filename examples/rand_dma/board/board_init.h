
#ifndef __BOARD_INIT_H__
#define __BOARD_INIT_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "hal_common.h"

#include "clock_init.h"

#define WS2812B_SPI_TX_PORT            SPI1
#define WS2812B_SPI_TX_FREQ            CLOCK_APB2_FREQ

#define WS2812B_SPI_TX_DMA_PORT        DMA1
#define WS2812B_SPI_TX_DMA_CHANNEL     DMA_REQ_DMA1_SPI1_TX

#define WS2812B_LED_NUM 1000

void BOARD_Init(void);
uint32_t BOARD_GetRunTimeMs(void);

#endif /* __BOARD_INIT_H__ */

