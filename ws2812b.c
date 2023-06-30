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

#include "ws2812b.h"
#include <stddef.h>

#define COLOR_BIT_00 0x88
#define COLOR_BIT_01 0x8E
#define COLOR_BIT_10 0xE8
#define COLOR_BIT_11 0xEE

/* color shift map.
 * make color val (8bit) to ws2812b data.
 */
const static uint8_t ws2812b_color_shift_map[256][4] =
{
    {COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_00}, /* 0x00 */
    {COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_01}, /* 0x01 */
    {COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_10}, /* 0x02 */
    {COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_11}, /* 0x03 */
    {COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_00}, /* 0x04 */
    {COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_01}, /* 0x05 */
    {COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_10}, /* 0x06 */
    {COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_11}, /* 0x07 */
    {COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_00}, /* 0x08 */
    {COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_01}, /* 0x09 */
    {COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_10}, /* 0x0A */
    {COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_11}, /* 0x0B */
    {COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_00}, /* 0x0C */
    {COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_01}, /* 0x0D */
    {COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_10}, /* 0x0E */
    {COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_11}, /* 0x0F */
    {COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_00}, /* 0x10 */
    {COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_01}, /* 0x11 */
    {COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_10}, /* 0x12 */
    {COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_11}, /* 0x13 */
    {COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_00}, /* 0x14 */
    {COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_01}, /* 0x15 */
    {COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_10}, /* 0x16 */
    {COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_11}, /* 0x17 */
    {COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_00}, /* 0x18 */
    {COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_01}, /* 0x19 */
    {COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_10}, /* 0x1A */
    {COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_11}, /* 0x1B */
    {COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_00}, /* 0x1C */
    {COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_01}, /* 0x1D */
    {COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_10}, /* 0x1E */
    {COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_11}, /* 0x1F */
    {COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_00}, /* 0x20 */
    {COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_01}, /* 0x21 */
    {COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_10}, /* 0x22 */
    {COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_11}, /* 0x23 */
    {COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_00}, /* 0x24 */
    {COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_01}, /* 0x25 */
    {COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_10}, /* 0x26 */
    {COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_11}, /* 0x27 */
    {COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_00}, /* 0x28 */
    {COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_01}, /* 0x29 */
    {COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_10}, /* 0x2A */
    {COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_11}, /* 0x2B */
    {COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_00}, /* 0x2C */
    {COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_01}, /* 0x2D */
    {COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_10}, /* 0x2E */
    {COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_11}, /* 0x2F */
    {COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_00}, /* 0x30 */
    {COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_01}, /* 0x31 */
    {COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_10}, /* 0x32 */
    {COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_11}, /* 0x33 */
    {COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_00}, /* 0x34 */
    {COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_01}, /* 0x35 */
    {COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_10}, /* 0x36 */
    {COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_11}, /* 0x37 */
    {COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_00}, /* 0x38 */
    {COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_01}, /* 0x39 */
    {COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_10}, /* 0x3A */
    {COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_11}, /* 0x3B */
    {COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_00}, /* 0x3C */
    {COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_01}, /* 0x3D */
    {COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_10}, /* 0x3E */
    {COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_11}, /* 0x3F */
    {COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_00}, /* 0x40 */
    {COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_01}, /* 0x41 */
    {COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_10}, /* 0x42 */
    {COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_11}, /* 0x43 */
    {COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_00}, /* 0x44 */
    {COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_01}, /* 0x45 */
    {COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_10}, /* 0x46 */
    {COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_11}, /* 0x47 */
    {COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_00}, /* 0x48 */
    {COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_01}, /* 0x49 */
    {COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_10}, /* 0x4A */
    {COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_11}, /* 0x4B */
    {COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_00}, /* 0x4C */
    {COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_01}, /* 0x4D */
    {COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_10}, /* 0x4E */
    {COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_11}, /* 0x4F */
    {COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_00}, /* 0x50 */
    {COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_01}, /* 0x51 */
    {COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_10}, /* 0x52 */
    {COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_11}, /* 0x53 */
    {COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_00}, /* 0x54 */
    {COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_01}, /* 0x55 */
    {COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_10}, /* 0x56 */
    {COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_11}, /* 0x57 */
    {COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_00}, /* 0x58 */
    {COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_01}, /* 0x59 */
    {COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_10}, /* 0x5A */
    {COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_11}, /* 0x5B */
    {COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_00}, /* 0x5C */
    {COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_01}, /* 0x5D */
    {COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_10}, /* 0x5E */
    {COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_11}, /* 0x5F */
    {COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_00}, /* 0x60 */
    {COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_01}, /* 0x61 */
    {COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_10}, /* 0x62 */
    {COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_11}, /* 0x63 */
    {COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_00}, /* 0x64 */
    {COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_01}, /* 0x65 */
    {COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_10}, /* 0x66 */
    {COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_11}, /* 0x67 */
    {COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_00}, /* 0x68 */
    {COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_01}, /* 0x69 */
    {COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_10}, /* 0x6A */
    {COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_11}, /* 0x6B */
    {COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_00}, /* 0x6C */
    {COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_01}, /* 0x6D */
    {COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_10}, /* 0x6E */
    {COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_11}, /* 0x6F */
    {COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_00}, /* 0x70 */
    {COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_01}, /* 0x71 */
    {COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_10}, /* 0x72 */
    {COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_11}, /* 0x73 */
    {COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_00}, /* 0x74 */
    {COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_01}, /* 0x75 */
    {COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_10}, /* 0x76 */
    {COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_11}, /* 0x77 */
    {COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_00}, /* 0x78 */
    {COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_01}, /* 0x79 */
    {COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_10}, /* 0x7A */
    {COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_11}, /* 0x7B */
    {COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_00}, /* 0x7C */
    {COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_01}, /* 0x7D */
    {COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_10}, /* 0x7E */
    {COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_11}, /* 0x7F */
    {COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_00}, /* 0x80 */
    {COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_01}, /* 0x81 */
    {COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_10}, /* 0x82 */
    {COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_11}, /* 0x83 */
    {COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_00}, /* 0x84 */
    {COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_01}, /* 0x85 */
    {COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_10}, /* 0x86 */
    {COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_11}, /* 0x87 */
    {COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_00}, /* 0x88 */
    {COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_01}, /* 0x89 */
    {COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_10}, /* 0x8A */
    {COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_11}, /* 0x8B */
    {COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_00}, /* 0x8C */
    {COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_01}, /* 0x8D */
    {COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_10}, /* 0x8E */
    {COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_11}, /* 0x8F */
    {COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_00}, /* 0x90 */
    {COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_01}, /* 0x91 */
    {COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_10}, /* 0x92 */
    {COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_11}, /* 0x93 */
    {COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_00}, /* 0x94 */
    {COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_01}, /* 0x95 */
    {COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_10}, /* 0x96 */
    {COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_11}, /* 0x97 */
    {COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_00}, /* 0x98 */
    {COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_01}, /* 0x99 */
    {COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_10}, /* 0x9A */
    {COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_11}, /* 0x9B */
    {COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_00}, /* 0x9C */
    {COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_01}, /* 0x9D */
    {COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_10}, /* 0x9E */
    {COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_11}, /* 0x9F */
    {COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_00}, /* 0xA0 */
    {COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_01}, /* 0xA1 */
    {COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_10}, /* 0xA2 */
    {COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_11}, /* 0xA3 */
    {COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_00}, /* 0xA4 */
    {COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_01}, /* 0xA5 */
    {COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_10}, /* 0xA6 */
    {COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_11}, /* 0xA7 */
    {COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_00}, /* 0xA8 */
    {COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_01}, /* 0xA9 */
    {COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_10}, /* 0xAA */
    {COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_11}, /* 0xAB */
    {COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_00}, /* 0xAC */
    {COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_01}, /* 0xAD */
    {COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_10}, /* 0xAE */
    {COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_11}, /* 0xAF */
    {COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_00}, /* 0xB0 */
    {COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_01}, /* 0xB1 */
    {COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_10}, /* 0xB2 */
    {COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_11}, /* 0xB3 */
    {COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_00}, /* 0xB4 */
    {COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_01}, /* 0xB5 */
    {COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_10}, /* 0xB6 */
    {COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_11}, /* 0xB7 */
    {COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_00}, /* 0xB8 */
    {COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_01}, /* 0xB9 */
    {COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_10}, /* 0xBA */
    {COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_11}, /* 0xBB */
    {COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_00}, /* 0xBC */
    {COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_01}, /* 0xBD */
    {COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_10}, /* 0xBE */
    {COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_11}, /* 0xBF */
    {COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_00}, /* 0xC0 */
    {COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_01}, /* 0xC1 */
    {COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_10}, /* 0xC2 */
    {COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_00, COLOR_BIT_11}, /* 0xC3 */
    {COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_00}, /* 0xC4 */
    {COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_01}, /* 0xC5 */
    {COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_10}, /* 0xC6 */
    {COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_01, COLOR_BIT_11}, /* 0xC7 */
    {COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_00}, /* 0xC8 */
    {COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_01}, /* 0xC9 */
    {COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_10}, /* 0xCA */
    {COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_10, COLOR_BIT_11}, /* 0xCB */
    {COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_00}, /* 0xCC */
    {COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_01}, /* 0xCD */
    {COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_10}, /* 0xCE */
    {COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_11, COLOR_BIT_11}, /* 0xCF */
    {COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_00}, /* 0xD0 */
    {COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_01}, /* 0xD1 */
    {COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_10}, /* 0xD2 */
    {COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_00, COLOR_BIT_11}, /* 0xD3 */
    {COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_00}, /* 0xD4 */
    {COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_01}, /* 0xD5 */
    {COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_10}, /* 0xD6 */
    {COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_01, COLOR_BIT_11}, /* 0xD7 */
    {COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_00}, /* 0xD8 */
    {COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_01}, /* 0xD9 */
    {COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_10}, /* 0xDA */
    {COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_10, COLOR_BIT_11}, /* 0xDB */
    {COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_00}, /* 0xDC */
    {COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_01}, /* 0xDD */
    {COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_10}, /* 0xDE */
    {COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_11, COLOR_BIT_11}, /* 0xDF */
    {COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_00}, /* 0xE0 */
    {COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_01}, /* 0xE1 */
    {COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_10}, /* 0xE2 */
    {COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_00, COLOR_BIT_11}, /* 0xE3 */
    {COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_00}, /* 0xE4 */
    {COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_01}, /* 0xE5 */
    {COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_10}, /* 0xE6 */
    {COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_01, COLOR_BIT_11}, /* 0xE7 */
    {COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_00}, /* 0xE8 */
    {COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_01}, /* 0xE9 */
    {COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_10}, /* 0xEA */
    {COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_10, COLOR_BIT_11}, /* 0xEB */
    {COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_00}, /* 0xEC */
    {COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_01}, /* 0xED */
    {COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_10}, /* 0xEE */
    {COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_11, COLOR_BIT_11}, /* 0xEF */
    {COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_00}, /* 0xF0 */
    {COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_01}, /* 0xF1 */
    {COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_10}, /* 0xF2 */
    {COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_00, COLOR_BIT_11}, /* 0xF3 */
    {COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_00}, /* 0xF4 */
    {COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_01}, /* 0xF5 */
    {COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_10}, /* 0xF6 */
    {COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_01, COLOR_BIT_11}, /* 0xF7 */
    {COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_00}, /* 0xF8 */
    {COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_01}, /* 0xF9 */
    {COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_10}, /* 0xFA */
    {COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_10, COLOR_BIT_11}, /* 0xFB */
    {COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_00}, /* 0xFC */
    {COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_01}, /* 0xFD */
    {COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_10}, /* 0xFE */
    {COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_11, COLOR_BIT_11}, /* 0xFF */
};

/*!
 * @brief default fx.
 * the fx make all led close.
 * @param led_idx the led index.
 * @param color the point of color val for the led.
 * @param param the point of param val for the led.
 * @return none.
 */
static void default_fx(uint32_t led_idx, ws2812b_color_t *color, void *param)
{
    (void) led_idx;
    (void) param;

    color->ch.r = 0x00;
    color->ch.g = 0x00;
    color->ch.b = 0x00;
}

/*!
 * @brief init ws2812b
 * @param ws2812b the instance of ws2812b.
 * @param ws2812b_if the interface of ws2812b.
 * @return none.
 */
void ws2812b_init      (ws2812b_t *ws2812b, ws2812b_if_t *ws2812b_if)
{
    ws2812b->ws2812b_if = ws2812b_if;
    ws2812b->ws2812b_fx = default_fx;
    ws2812b->fx_param   = NULL;
    ws2812b_if->hw_init();
}

/*!
 * @brief set ws2812b fx.
 * @param ws2812b the instance of ws2812b.
 * @param ws2812b_fx the func of fx.
 * @param param the param to send fx.
 * @return none.
 */
void ws2812b_set_fx    (ws2812b_t *ws2812b, ws2812b_fx_t  ws2812b_fx, void *param)
{
    ws2812b->ws2812b_fx = ws2812b_fx;
    ws2812b->fx_param   = param;
}

/*!
 * @brief flush ws2812b data by polling mode.
 * the func will finished until the ws2812b data send done.
 * @param ws2812b the instance of ws2812b.
 * @return none.
 */
void ws2812b_poll(ws2812b_t *ws2812b)
{
    if (ws2812b->ws2812b_fx          == NULL
    &&  ws2812b->ws2812b_if->hw_send == NULL)
    {
        return;
    }

    uint32_t          led_num  = ws2812b->ws2812b_if->led_num;
    ws2812b_hw_send_t hw_send  = ws2812b->ws2812b_if->hw_send;
    ws2812b_fx_t      fx       = ws2812b->ws2812b_fx;
    void             *fx_param = ws2812b->fx_param;

    ws2812b_color_t color = {0};
    for(uint32_t led_idx = 0; led_idx < led_num; led_idx++)
    {
        color.val = 0;
        fx(led_idx, &color, fx_param);

        hw_send(ws2812b_color_shift_map[color.ch.g][0]);
        hw_send(ws2812b_color_shift_map[color.ch.g][1]);
        hw_send(ws2812b_color_shift_map[color.ch.g][2]);
        hw_send(ws2812b_color_shift_map[color.ch.g][3]);

        hw_send(ws2812b_color_shift_map[color.ch.r][0]);
        hw_send(ws2812b_color_shift_map[color.ch.r][1]);
        hw_send(ws2812b_color_shift_map[color.ch.r][2]);
        hw_send(ws2812b_color_shift_map[color.ch.r][3]);

        hw_send(ws2812b_color_shift_map[color.ch.b][0]);
        hw_send(ws2812b_color_shift_map[color.ch.b][1]);
        hw_send(ws2812b_color_shift_map[color.ch.b][2]);
        hw_send(ws2812b_color_shift_map[color.ch.b][3]);
    }
}

/*!
 * @brief flush ws2812b data by dma mode.
 * @param ws2812b the instance of ws2812b.
 * @return none.
 */
void ws2812b_dma (ws2812b_t *ws2812b)
{
    uint32_t         led_num  = ws2812b->ws2812b_if->led_num;
    uint8_t         *dma_buf  = ws2812b->ws2812b_if->dma_buf;
    ws2812b_hw_dma_t hw_dma   = ws2812b->ws2812b_if->hw_dma;
    ws2812b_fx_t     fx       = ws2812b->ws2812b_fx;
    void            *fx_param = ws2812b->fx_param;

    ws2812b_color_t color = {0};
    for(uint32_t led_idx = 0; led_idx < led_num; led_idx++)
    {
        color.val = 0;
        fx(led_idx, &color, fx_param);

        *dma_buf++ = ws2812b_color_shift_map[color.ch.g][0];
        *dma_buf++ = ws2812b_color_shift_map[color.ch.g][1];
        *dma_buf++ = ws2812b_color_shift_map[color.ch.g][2];
        *dma_buf++ = ws2812b_color_shift_map[color.ch.g][3];

        *dma_buf++ = ws2812b_color_shift_map[color.ch.r][0];
        *dma_buf++ = ws2812b_color_shift_map[color.ch.r][1];
        *dma_buf++ = ws2812b_color_shift_map[color.ch.r][2];
        *dma_buf++ = ws2812b_color_shift_map[color.ch.r][3];

        *dma_buf++ = ws2812b_color_shift_map[color.ch.b][0];
        *dma_buf++ = ws2812b_color_shift_map[color.ch.b][1];
        *dma_buf++ = ws2812b_color_shift_map[color.ch.b][2];
        *dma_buf++ = ws2812b_color_shift_map[color.ch.b][3];
    }

    hw_dma();
}
