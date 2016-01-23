/******************************************************************
 * sysctl.cc
 *
 *  Created on: Jan 16, 2016
 *      Author: root
 ******************************************************************/

#include "stdbool.h"
#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "sysctl.hh"

namespace lib
{

Sysctl::Sysctl( uint32_t base ) :
		Peripheral(base)
{
}

Sysctl::~Sysctl()
{
	// TODO Auto-generated destructor stub
}

void Sysctl::set_clock()
{
	uint32_t u32Delay = 524288;

	// 1) Bypas the PLL and system clock divider.
	setRegBit(RCC, SYSCTL_RCC_BYPASS);
	clearRegBit(RCC, SYSCTL_RCC_USESYSDIV);
	clearRegBit(RCC2, SYSCTL_RCC2_USERCC2);

	// 2.1) Enable the Main Oscilator
	// Clear the MOSC power up raw interrupt status to be sure it is not set when waiting below.
	setRegBit(MISC, SYSCTL_MISC_MOSCPUPMIS);
	// Make sure that the required oscillators are enabled.
	clearRegBit(RCC, SYSCTL_RCC_MOSCDIS);
	// Timeout using the legacy delay value.
	while (0 == getRegField(RIS, SYSCTL_RIS_MOSCPUPRIS))
	{
		u32Delay--;
		if (u32Delay == 0)
		{
			break;
		}
	}
	// If the main oscillator failed to start up then do not switch to it and return.
	if (u32Delay == 0)
	{
		return;
	}
	// 2.2) Set the new crystal value and oscillator source.
	setRegField(RCC, SYSCTL_RCC_OSCSRC_M, SYSCTL_RCC_OSCSRC_MAIN);
	setRegField(RCC, SYSCTL_RCC_XTAL_M, SYSCTL_RCC_XTAL_16MHZ);

	// 3) Set the new PLL configuration and clear lock event.
	clearRegBit(RCC, SYSCTL_RCC_PWRDN);
	setRegValue(MISC, SYSCTL_MISC_PLLLMIS);

	// 3.2)Set the requested system divider and disable the appropriate
	// oscillators.  This value is not written immediately.
	setRegBit(RCC, SYSCTL_RCC_USESYSDIV);
	setRegField(RCC, SYSCTL_RCC_SYSDIV_M, SYSDIV4);

	// Wait until the PLL has locked.
	for (u32Delay = 32768; u32Delay > 0; u32Delay--)
	{
		if (0 != getRegField(PLLSTAT, SYSCTL_PLLSTAT_LOCK))
		{
			break;
		}
	}

	// Enable use of the PLL.
	clearRegBit(RCC, SYSCTL_RCC_BYPASS);

	// Delay for a little bit so that the system divider takes effect.*/
	for (u32Delay = 20000; u32Delay > 0; u32Delay--)
	{
		//NOP
	}
}

void Sysctl::peripheral_enable( enPeripherals peripheral )
{
	volatile uint32_t * pu32EnableRegister;
	uint8_t u8PerOffeset = ((peripheral & 0xff00) >> 8);
	uint8_t u8Peripheral = peripheral & 0xff;

	pu32EnableRegister = (volatile uint32_t*) (0x400fe000 + RCGCx + u8PerOffeset);
	*pu32EnableRegister = u8Peripheral;
}

void Sysctl::set_gpio_bus( enGPIOHBCTL gpio, enBus bus )
{
	if (bus)
	{
		setRegValue(GPIOHBCTL, getRegValue(GPIOHBCTL) | gpio);
	}
	else
	{
		setRegValue(GPIOHBCTL, (getRegValue(GPIOHBCTL) & ~gpio));
	}
}

uint32_t Sysctl::get_gpio_bus( enGPIOHBCTL gpio )
{
	return (getRegValue(GPIOHBCTL));
}

} /* namespace lib */
