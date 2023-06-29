#include "board_init.h"
#include "ws2812b.h"

/*
 * Macros.
 */

#define APP_WAIT_TIME_MS    500

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
    uint8_t seed = 0;
    uint32_t systime = 0;

    BOARD_Init();

    /* init ws2812b. */
    ws2812b_init(&ws2812b, &ws2812b_if);
    ws2812b_set_fx(&ws2812b, fx, &seed);

    while(true)
    {
        systime = BOARD_GetRunTimeMs();
        ws2812b_dma(&ws2812b);
        while(BOARD_GetRunTimeMs() - systime < APP_WAIT_TIME_MS){}
    }
}

void fx(uint32_t led_idx, ws2812b_color_t *color, void *param)
{
    (void) led_idx;

    uint32_t *seed = param;
    color->val = (*seed = *seed * 214013L + 2531011L) & 0x000F0F0F;
}

/* EOF. */
