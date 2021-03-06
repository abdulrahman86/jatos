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

#ifndef _PLATFORM_DRIVER_VGA_H
#define _PLATFORM_DRIVER_VGA_H

#include <io/ports.h>
#include <stdint.h>

// Memory base addresses for different VGA video modes
#define VGA_GFX_VIDEO_MEMORY            (0xA0000)   // Graphics mode
#define VGA_MONOCHROME_VIDEO_MEMORY     (0xB0000)   // Monochrome (uncolored) text mode
#define VGA_TM_VIDEO_MEMORY             (0xB8000)   // Text mode

// CRT Controller (CRTC) ports
#define VGA_CRTC_ADDRESS_PORT   (0x3D4)
#define VGA_CRTC_DATA_PORT      (0x3D5)

#define VGA_HORIZONTAL_TOTAL_REG            (0x00)
#define VGA_END_HORIZONTAL_DISPLAY_REG      (0x01)
#define VGA_START_HORIZONTAL_BLANKING_REG   (0x02)
#define VGA_END_HORIZONTAL_BLANKING_REG     (0x03)
#define VGA_START_HORIZONTAL_RETRACE_REG    (0x04)
#define VGA_END_HORIZONTAL_RETRACE_REG      (0x05)
#define VGA_VERTICAL_TOTAL_REG              (0x06)
#define VGA_OVERFLOW_REG                    (0x07)
#define VGA_PRESET_ROW_SCANLINE_REG         (0x08)
#define VGA_MAXIMUM_SCANLINE_REG            (0x09)
#define VGA_CURSOR_START_REG                (0x0A)
#define VGA_CURSOR_END_REG                  (0x0B)
#define VGA_START_ADDRESS_HIGH_REG          (0x0C)
#define VGA_START_ADDRESS_LOW_REG           (0x0D)
#define VGA_CURSOR_LOCATION_HIGH_REG        (0x0E)
#define VGA_CURSOR_LOCATION_LOW_REG         (0x0F)
#define VGA_START_VERTICAL_RETRACE_REG      (0x10)
#define VGA_END_VERTICAL_RETRACE_REG        (0x11)
#define VGA_END_VERTICAL_DISPLAY_REG        (0x12)
#define VGA_OFFSET_REG                      (0x13)
#define VGA_UNDERLINE_LOCATION_REG          (0x14)
#define VGA_START_VERTICAL_BLANKING_REG     (0x15)
#define VGA_END_VERTICAL_BLANKING_REG       (0x16)
#define VGA_CRTC_MODE_CONTROL_REG           (0x17)
#define VGA_LINE_COMPARE_REG                (0x18)

// Graphics Controller (GC) ports
#define VGA_GC_ADDRESS_PORT     (0x3CE)
#define VGA_GC_DATA_PORT        (0x3CF)

#define VGA_SET_RESET_REG               (0x00)
#define VGA_ENABLE_SET_RESET_REG        (0x01)
#define VGA_COLOR_CMP_REG               (0x02)
#define VGA_DATA_ROTATE_REG             (0x03)
#define VGA_READ_MAP_SELECT_REG         (0x04)
#define VGA_GRAPHICS_MODE_REG           (0x05)
#define VGA_MISC_GRAPHICS_REG           (0x06)
#define VGA_IGNORE_COLOR_REG            (0x07)
#define VGA_BITMASK_REG                 (0x08)

// Sequencer (SEQ) ports
#define VGA_SEQ_ADDRESS_PORT     (0x3C4)
#define VGA_SEQ_DATA_PORT        (0x3C5)

#define VGA_RESET_REG               (0x00)
#define VGA_CLOCKING_MODE_REG       (0x01)
#define VGA_MAP_MASK_REG            (0x02)
#define VGA_CHARACTER_MAP_REG       (0x03)
#define VGA_SEQ_MEMORY_MODE_REG     (0x04)

// Attribute Controller (AC)
#define VGA_AC_ADDRESS_PORT     (0x3C0)
#define VGA_AC_WRITE_PORT       (0x3C0)
#define VGA_AC_READ_PORT        (0x3C1)
#define VGA_AC_RESET_PORT       (0x3DA)

// Misc Controller (MISC)
#define VGA_MISC_WRITE_PORT     (0x3C2)
#define VGA_MISC_READ_PORT      (0x3CC)

#define VGA_VIDEO_MODES (20)    // Standart VGA supports 20 potential video modes

// List of supported VGA video modes
typedef enum {

    VGA_80X25X16_TEXT = 0x03,
    VGA_320X200X256_GFX = 0x13
}
vga_mode_t;

// Change the VGA video mode
int32_t vga_init(vga_mode_t mode);

#endif // _PLATFORM_DRIVER_VGA_H