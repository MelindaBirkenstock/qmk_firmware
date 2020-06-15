/* Copyright 2020 Richard Head
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CHEEM_H
#define CHEEM_H

#include "quantum.h"
#include <stdint.h>
#include <stdbool.h>
#include "i2c_master.h"
#include <util/delay.h>

// I2C aliases and register addresses (see "mcp23018.md" on tmk repository)
// https://github.com/benblazak/ergodox-firmware/blob/master/src/keyboard/ergodox/controller/mcp23018.md
#define I2C_ADDR        0b0100000
#define I2C_ADDR_WRITE  ( (I2C_ADDR<<1) | I2C_WRITE )
#define I2C_ADDR_READ   ( (I2C_ADDR<<1) | I2C_READ  )
#define IODIRA          0x00            // i/o direction register
#define IODIRB          0x01
#define GPPUA           0x0C            // GPIO pull-up resistor register
#define GPPUB           0x0D
#define GPIOA           0x12            // general purpose i/o port register (write modifies OLAT)
#define GPIOB           0x13
#define OLATA           0x14            // output latch register
#define OLATB           0x15

extern i2c_status_t mcp23018_status;

#define I2C_TIMEOUT 1000

void init_chem(void);
uint8_t init_mcp23018(void);

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    k00, k01, k02, k03, k04,    k40, k41, k42, k43, k44, \
    k10, k11, k12, k13, k14,    k50, k51, k52, k53, k54, \
    k20, k21, k22, k23, k24,    k60, k61, k62, k63, k64, \
                   k33, k34,    k70, k71                 \
) \
{ \
    { k00,   k01,   k02,   k03,   k04 }, \
    { k10,   k11,   k12,   k13,   k14 }, \
    { k20,   k21,   k22,   k23,   k24 }, \
    { KC_NO, KC_NO, KC_NO, k33,   k34 }, \
    { k40,   k41,   k42,   k43,   k44 }, \
    { k50,   k51,   k52,   k53,   k54 }, \
    { k60,   k61,   k62,   k63,   k64 }, \
    { k70,   k71,   KC_NO, KC_NO, KC_NO }, \
}
#endif
