#include "board_init.h"
#include "ws2812b.h"

/*
 * Macros.
 */

#define APP_WAIT_TIME_MS    10

/*
 * Variables.
 */

extern ws2812b_if_t ws2812b_if;
ws2812b_t ws2812b;

/*
 * Declerations.
 */

void fx(uint32_t led_idx, ws2812b_color_t *color, void *param);

/*
 * Functions.
 */

int main(void)
{
    uint8_t brightness = 0;
    uint32_t systime = 0;

    BOARD_Init();

    /* init ws2812b. */
    ws2812b_init(&ws2812b, &ws2812b_if);
    ws2812b_set_fx(&ws2812b, fx, &brightness);

    while(true)
    {
        /* brightness++ */
        for (uint32_t i = 0; i < 50; i++)
        {
            systime = BOARD_GetRunTimeMs();
            brightness++;
            ws2812b_poll(&ws2812b);
            while(BOARD_GetRunTimeMs() - systime < APP_WAIT_TIME_MS){}
        }
        /* brightness-- */
        for (uint32_t i = 0; i < 50; i++)
        {
            systime = BOARD_GetRunTimeMs();
            brightness--;
            ws2812b_poll(&ws2812b);
            while(BOARD_GetRunTimeMs() - systime < APP_WAIT_TIME_MS){}
        }
    }
}

void fx(uint32_t led_idx, ws2812b_color_t *color, void *param)
{
    (void) led_idx;

    color->val = 0;
    switch (led_idx % 3)
    {
        case 0:
            color->ch.r = *((uint8_t*)param);
            break;
        case 1:
            color->ch.g = *((uint8_t*)param);
            break;
        case 2:
            color->ch.b = *((uint8_t*)param);
            break;
        default:
            break;
            
    }
}

/* EOF. */
