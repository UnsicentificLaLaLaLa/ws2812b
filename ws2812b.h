/*
 * MIT License
 *
 * Copyright (c) 2023 UnsicentificLaLaLaLa
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#ifndef WS2812B_H
#define WS2812B_H

#include <stdint.h>

/*!
 * @brief the spi sck frequency.
 * when init spi, the sck frequency must equal this val.
 */
#define WS2812B_SPI_SCK_FREQ        4000000

/*!
 * @brief define the dma minimal buffer size.
 * @param led_num the ws2812b led numbers.
 * @return the buffer size of dma.
 */
#define WS2812B_BUF_SIZE(led_num)   ((led_num) * 3 * 4)

/*!
 * @brief ws2812b color type.
 * record the color val.
 */
typedef union {
    struct {
        uint32_t r :8;  /* red channel value. */
        uint32_t g :8;  /* green channel value. */
        uint32_t b :8;  /* blue channel value. */
        uint32_t a :8;  /* alpha channel value, not used. */
    }ch;
    uint32_t val;       /* color value, 0xAARRGGBB. */
} ws2812b_color_t;

/*!
 * @brief ws2812b init hardware func type.
 * @param none.
 * @return none.
 */
typedef void (*ws2812b_hw_init_t)(void);

/*!
 * @brief ws2812b send data by spi func type.
 * @param val the val need to send by spi.
 * @return none.
 */
typedef void (*ws2812b_hw_send_t)(uint8_t  val);

/*!
 * @brief ws2812b start dma func type.
 * @param none.
 * @return none.
 */
typedef void (*ws2812b_hw_dma_t) (void);

/*!
 * @brief ws2812b fx func type.
 * @param led_idx the led index.
 * @param color the point of color val for the led.
 * @param param the point of param val for the led.
 * @return none.
 */
typedef void (*ws2812b_fx_t)     (uint32_t led_idx, ws2812b_color_t *color, void *param);

/*!
 * @brief ws2812b interface type.
 * record the hardware func.
 */
typedef struct {
    uint32_t          led_num; /* record the number of leds. */
    uint8_t          *dma_buf; /* record the dma buffer. */
    ws2812b_hw_init_t hw_init; /* the func of init hardware. */
    ws2812b_hw_send_t hw_send; /* the func of send data by spi. */
    ws2812b_hw_dma_t  hw_dma;  /* the func of start dma transfer. */
} ws2812b_if_t;

/*!
 * @brief ws2812b instance type.
 * record the ws2812b info.
 */
typedef struct {
    ws2812b_if_t *ws2812b_if; /* the interface of ws2812b. */
    ws2812b_fx_t  ws2812b_fx; /* the fx of ws2812b. */
    void         *fx_param;
} ws2812b_t;

/*!
 * @brief init ws2812b
 * @param ws2812b the instance of ws2812b.
 * @param ws2812b_if the interface of ws2812b.
 * @return none.
 */
void ws2812b_init      (ws2812b_t *ws2812b, ws2812b_if_t *ws2812b_if);

/*!
 * @brief set ws2812b fx.
 * @param ws2812b the instance of ws2812b.
 * @param ws2812b_fx the func of fx.
 * @param param the param to send fx.
 * @return none.
 */
void ws2812b_set_fx    (ws2812b_t *ws2812b, ws2812b_fx_t  ws2812b_fx, void *param);

/*!
 * @brief flush ws2812b data by polling mode.
 * the func will finished until the ws2812b data send done.
 * @param ws2812b the instance of ws2812b.
 * @return none.
 */
void ws2812b_poll(ws2812b_t *ws2812b);

/*!
 * @brief flush ws2812b data by dma mode.
 * @param ws2812b the instance of ws2812b.
 * @return none.
 */
void ws2812b_dma (ws2812b_t *ws2812b);

#endif /* WS2812B_H */
