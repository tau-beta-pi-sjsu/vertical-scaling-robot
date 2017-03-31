#ifndef BOARD_H
#define BOARD_H

#if spi 
#include "spi1.h"

void access_SPI(){
	// Sends 0xDEAD over to the SPI device and gets 2 bytes back:
	chip_select_my_device(true);
	{
		char byte_0 = spil_exchange_byte(0xDE);
		char byte_1 = spil_exchange_byte(0xAD);
	}
	chip_select_my_device(false);

	/*
	 * You can use any GPIO for CS (chip-select) signal.
	 * This examples assumes CS is done through a function:
	 * chip_select_my_device(bool);
	 */
}

#elif i2c
#include "I2C2.hpp"

void send_byte_to_my_i2c_device()
{
    const char my_dev_addr = 0xBA; // Your device address
    const char my_dev_reg  = 0x01; // Write to 1st register of your device
    const char my_dev_data = 0xAB; // Write 0xAB to reg 0x01
    I2C2::getInstance().writeReg(my_dev_addr, my_dev_reg, my_dev_data);

	/*
	 * I2C2 is a namespace as used in this example
	 * Utilize the connection to hook up external I2C devices
	 * This example assumes a function and dot operator
	 */
}

#endif