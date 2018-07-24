/* mbed Microcontroller Library
 * Copyright (c) 2017 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
  Modifications copyright (C) 2018 GreenWaves Technologies
  - Change the i2cee pin mapping for GAP8
*/

// Here's an example using a M24M02-DRMN6 on GAP8
#include "mbed.h"
#include "I2CEEBlockDevice.h"

// Create EEPROM device on I2C bus with 256kbytes of memory, 256 byte page, 100 KHz
I2CEEBlockDevice i2cee(I2C0_SDA, I2C0_SCL, 0xA0, 256*1024, 256, 100000);

int main() {
    printf("i2cee test\n");

    // Initialize the device and print the memory layout
    i2cee.init();
    printf("i2cee size: %llu\n",         i2cee.size());
    printf("i2cee read size: %llu\n",    i2cee.get_read_size());
    printf("i2cee program size: %llu\n", i2cee.get_program_size());
    printf("i2cee erase size: %llu\n",   i2cee.get_erase_size());

    // Write "Hello World!" to the first block
    void *buffer = malloc(i2cee.get_erase_size());
    sprintf((char*) buffer, "Hello World!\n");
    i2cee.erase(0, i2cee.get_erase_size());
    i2cee.program(buffer, 0, i2cee.get_erase_size());

    // Read back what was stored
    i2cee.read(buffer, 0, i2cee.get_erase_size());
    printf("%s", (char*) buffer);

    // Deinitialize the device
    i2cee.deinit();
    free(buffer);
}
