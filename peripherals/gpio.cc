/******************************************************************
 * gpio.cc
 *
 *  Created on: Jan 16, 2016
 *      Author: root
 ******************************************************************/

#include "stdbool.h"
#include "stdint.h"
#include "gpio.hh"

namespace lib
{

Gpio::Gpio(uint32_t base): Peripheral(base)
{
	
}

void Gpio::setPinAsOutput(enPorts port, enPins pin)
{

}

Gpio::~Gpio()
{
	// TODO Auto-generated destructor stub
}

} /* namespace lib */
