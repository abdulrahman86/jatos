/*
 * MIT License
 *
 * Copyright (c) 2019 0x1C1B
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

#ifndef _PLATFORM_DRIVER_VGA_GFX_H
#define _PLATFORM_DRIVER_VGA_GFX_H

#include <driver/video/vga/vga.h>

#include <string.h>
#include <stdint.h>

/*
    Screen is divided into separate colorful pixels that are organized in a
    coordinate system.
*/

#define VGA_GFX_HEIGHT  (200)
#define VGA_GFX_WIDTH   (320)
#define VGA_GFX_PIXELS  (VGA_GFX_HEIGHT * VGA_GFX_WIDTH)

// The first 16 VGA colors of VGA 256-Color palette
#define VGA_GFX_BLACK           (0x00)
#define VGA_GFX_BLUE            (0x01)
#define VGA_GFX_GREEN           (0x02)
#define VGA_GFX_CYAN            (0x03)
#define VGA_GFX_RED             (0x04)
#define VGA_GFX_MAGENTA         (0x05)
#define VGA_GFX_BROWN           (0x06)
#define VGA_GFX_LIGHT_GRAY      (0x07)
#define VGA_GFX_DARK_GRAY       (0x08)
#define VGA_GFX_LIGHT_BLUE      (0x09)
#define VGA_GFX_LIGHT_GREEN     (0x0A)
#define VGA_GFX_LIGHT_CYA       (0x0B)
#define VGA_GFX_LIGHT_MAGENTA   (0x0C)
#define VGA_GFX_YELLOW          (0x0E)
#define VGA_GFX_WHITE           (0x0F)

void vga_gfx_init();

void vga_gfx_fill(uint8_t color);
int32_t vga_gfx_put_pixel(uint32_t x, uint32_t y, uint8_t color);

#endif // _PLATFORM_DRIVER_VGA_GFX_H