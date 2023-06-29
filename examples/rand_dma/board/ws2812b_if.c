/* ws2812b_if.c */

#include "ws2812b.h"
#include "board_init.h"
#include "hal_spi.h"
#include "hal_dma.h"
#include "hal_dma_request.h"

static uint8_t ws2812b_if_buf[WS2812B_BUF_SIZE(WS2812B_LED_NUM)];

static void hw_init(void);
static void hw_dma(void);

ws2812b_if_t ws2812b_if = 
{
    .led_num = WS2812B_LED_NUM,
    .dma_buf = ws2812b_if_buf,
    .hw_init = hw_init,
    .hw_dma  = hw_dma,
};

static void hw_init(void)
{
    DMA_Channel_Init_Type dma_channel_init;
    dma_channel_init.XferMode = DMA_XferMode_MemoryToPeriph;
    dma_channel_init.ReloadMode = DMA_ReloadMode_AutoReload;
    dma_channel_init.PeriphAddrIncMode = DMA_AddrIncMode_StayAfterXfer;
    dma_channel_init.MemAddrIncMode = DMA_AddrIncMode_IncAfterXfer;
    dma_channel_init.XferWidth = DMA_XferWidth_8b;
    dma_channel_init.Priority = DMA_Priority_Low;
    dma_channel_init.XferCount = sizeof(ws2812b_if_buf);
    dma_channel_init.MemAddr = (uint32_t)ws2812b_if_buf;
    dma_channel_init.PeriphAddr = SPI_GetTxDataRegAddr(WS2812B_SPI_TX_PORT);
    DMA_InitChannel(WS2812B_SPI_TX_DMA_PORT, WS2812B_SPI_TX_DMA_CHANNEL, &dma_channel_init);

    SPI_Master_Init_Type spi_init;
    spi_init.ClockFreqHz = WS2812B_SPI_TX_FREQ;
    spi_init.BaudRate = WS2812B_SPI_SCK_FREQ;
    spi_init.XferMode = SPI_XferMode_TxRx;
    spi_init.PolPha = SPI_PolPha_Alt0;
    spi_init.DataWidth = SPI_DataWidth_8b;
    spi_init.LSB = false;
    spi_init.AutoCS = true;
    SPI_InitMaster(WS2812B_SPI_TX_PORT, &spi_init);
    SPI_EnableDMA(WS2812B_SPI_TX_PORT, true); /* Events would trigger the DMA instead of interrupt. */
    SPI_Enable(WS2812B_SPI_TX_PORT, true);
}

static void hw_dma(void)
{
    DMA_EnableChannel(WS2812B_SPI_TX_DMA_PORT, WS2812B_SPI_TX_DMA_CHANNEL, true);
}

/* EOF. */