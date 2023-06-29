
#include "pin_init.h"
#include "hal_rcc.h"
#include "hal_gpio.h"

/*
 * TXD2 - PA2.
 * RXD2 - PA3.
 */
void BOARD_InitPins(void)
{
    GPIO_Init_Type gpio_init;

    /* PB5 - SPI1_MOSI. */
    gpio_init.Pins  = GPIO_PIN_5;
    gpio_init.PinMode  = GPIO_PinMode_AF_PushPull;
    gpio_init.Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &gpio_init);
    GPIO_PinAFConf(GPIOB, gpio_init.Pins, GPIO_AF_0);
}


/* EOF. */
