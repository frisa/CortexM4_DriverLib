/******************************************************************
 * gpio.hh
 *
 *  Created on: Jan 16, 2016
 *      Author: root
 ******************************************************************/

#ifndef GPIO_HH_
#define GPIO_HH_

#include "stdbool.h"
#include "stdint.h"
#include "peripheral.hh"

namespace lib
{

/*******************************************************************
 *
 *******************************************************************/
class Gpio : Peripheral
{
	enum enPorts
	{
		PORTA	= 0x001,
	};
	enum enPins
	{
		PIN0	= 0x001,
		PIN1	= 0x002,
		PIN2	= 0x004,
		PIN3	= 0x008,
		PIN4	= 0x010,
		PIN5	= 0x020,
		PIN6	= 0x040,
		PIN7	= 0x080,
	};
	enum enRegisters
	{
		GPIODIR = 0x400,
	};
	public:
		Gpio(uint32_t base);
		virtual ~Gpio();
		void setPinAsOutput(enPorts port, enPins pin);
};

} /* namespace lib */

#endif /* GPIO_HH_ */
