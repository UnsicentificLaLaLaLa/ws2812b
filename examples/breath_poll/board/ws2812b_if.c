/* ws2812b_if.c */

#include "ws2812b.h"
#include "board_init.h"
#include "hal_spi.h"
#include "hal_dma.h"
#include "hal_dma_request.h"

#define LED_NUM 8

static void hw_init(void);
static void hw_send(uint8_t val);
static void hw_dma(void);

ws2812b_if_t ws2812b_if = 
{
    .led_num = LED_NUM,
    .hw_init = hw_init,
    .hw_send = hw_send,
};

static void hw_init(void)
{
    SPI_Master_Init_Type spi_init;
    spi_init.ClockFreqHz = WS2812B_SPI_TX_FREQ;
    spi_init.BaudRate = WS2812B_SPI_SCK_FREQ;
    spi_init.XferMode = SPI_XferMode_TxRx;
    spi_init.PolPha = SPI_PolPha_Alt0;
    spi_init.DataWidth = SPI_DataWidth_8b;
    spi_init.LSB = false;
    spi_init.AutoCS = true;
    SPI_InitMaster(WS2812B_SPI_TX_PORT, &spi_init);
    SPI_Enable(WS2812B_SPI_TX_PORT, true);
}

static void hw_send(uint8_t val)
{
    while(0 != (SPI_GetStatus(WS2812B_SPI_TX_PORT) & SPI_STATUS_TX_FULL))
    {}

    SPI_PutData(WS2812B_SPI_TX_PORT, val);
}

/* EOF. */
