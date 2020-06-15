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

#include QMK_KEYBOARD_H

bool i2c_initialized = 0;
i2c_status_t mcp23018_status = 0x20;

void matrix_init_kb(void) {
  //// (tied to Vcc for hardware convenience)
  //DDRB  &= ~(1<<4);  // set B(4) as input
  //PORTB &= ~(1<<4);  // set B(4) internal pull-up disabled

    // unused pins - C7, D4, D5, D7, E6
    // set as input with internal pull-up enabled
    DDRC  &= ~(1<<7);
    DDRD  &= ~(1<<5 | 1<<4);
    DDRE  &= ~(1<<6);
    PORTC |=  (1<<7);
    PORTD |=  (1<<5 | 1<<4);
    PORTE |=  (1<<6);

    matrix_init_user();
}

uint8_t init_mcp23018(void) {
    mcp23018_status = 0x20;

    // I2C subsystem

    // uint8_t sreg_prev;
    // sreg_prev=SREG;
    // cli();

    if (i2c_initialized == 0) {
        i2c_init();
        i2c_initialized = true;
        _delay_ms(1000);
    }

    // set pin direction
    // - unused  : input  : 1
    // - input   : input  : 1
    // - driving : output : 0
    mcp23018_status = i2c_start(I2C_ADDR_WRITE, I2C_TIMEOUT);    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(IODIRA, I2C_TIMEOUT);            if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b00000000, I2C_TIMEOUT);        if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b00111111, I2C_TIMEOUT);        if (mcp23018_status) goto out;
    i2c_stop();

    // set pull-up
    // - unused  : on  : 1
    // - input   : on  : 1
    // - driving : off : 0
    mcp23018_status = i2c_start(I2C_ADDR_WRITE, I2C_TIMEOUT);    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(GPPUA, I2C_TIMEOUT);             if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b00000000, I2C_TIMEOUT);        if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b00111111, I2C_TIMEOUT);        if (mcp23018_status) goto out;

out:
    i2c_stop();

    return mcp23018_status;
}
