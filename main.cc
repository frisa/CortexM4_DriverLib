/*******************************************************
 * main.c
 *******************************************************/

#include "stdbool.h"
#include "stdint.h"

#include "peripherals/peripheral.hh"
#include "peripherals/sysctl.hh"
#include "peripherals/gpio.hh"

using namespace lib;

Sysctl g_sysctl(0x400fe000);
Sysctl * sysctl = &g_sysctl;

//Gpio g_gpio(0x4005d000);
//Gpio * gpio = &g_gpio;

int main( void )
{
	sysctl->set_clock();
	sysctl->set_gpio_bus(Sysctl::PORTF, Sysctl::nAhb);
	sysctl->peripheral_enable(Sysctl::nGPIOF);

	while(1)
	{

	}
}
