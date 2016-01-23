/******************************************************************
 * sysctl.hh
 *
 *  Created on: Jan 16, 2016
 *      Author: root
 ******************************************************************/

#ifndef SYSCTL_HH_
#define SYSCTL_HH_

#include "stdbool.h"
#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "peripheral.hh"

namespace lib
{

/*******************************************************************
 *
 *******************************************************************/
class Sysctl : Peripheral
{
	public:
		enum enPeripherals
		{
			// 0x<2xoffset><2xperipheral>
			nGPIOA = 0x0001,
			nGPIOB = 0x0002,
			nGPIOC = 0x0004,
			nGPIOD = 0x0008,
			nGPIOE = 0x0010,
			nGPIOF = 0x0020,
			nUART0 = 0x1000,
		};
		enum enGPIOHBCTL
		{
			PORTA = 0x0001,
			PORTB = 0x0002,
			PORTC = 0x0004,
			PORTD = 0x0008,
			PORTE = 0x0010,
			PORTF = 0x0020,
		};
		enum enConfig
		{
			SYSDIV4			= 0x01C00000,
		};
		enum enBus
		{
			nApb = 0,
			nAhb = 1,
		};
		enum enRegisters
		{
			RIS 		= 0x050,
			MISC 		= 0x058,
			RCC 		= 0x060,
			RCC2 		= 0x070,
			GPIOHBCTL 	= 0x06c,
			RCGCx		= 0x608,
			PLLSTAT 	= 0x168,
		};
	public:
		Sysctl(uint32_t base);
		virtual ~Sysctl();
		void set_clock();
		void peripheral_enable(enPeripherals peripheral);
		void set_gpio_bus(enGPIOHBCTL gpio, enBus bus);
		uint32_t get_gpio_bus(enGPIOHBCTL gpio);
};

} /* namespace lib */

#endif /* SYSCTL_HH_ */
