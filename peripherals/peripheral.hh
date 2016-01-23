/******************************************************************
 * Peripheral.hh
 *
 *  Created on: Jan 16, 2016
 *      Author: root
 ******************************************************************/

#ifndef PERIPHERALS_PERIPHERAL_HH_
#define PERIPHERALS_PERIPHERAL_HH_

#include "stdbool.h"
#include "stdint.h"

namespace lib
{

/*******************************************************************
 *
 *******************************************************************/
class Peripheral
{
	protected:
		const uint32_t m_base;

		inline volatile uint32_t* getRegAddr(uint32_t u32Offset)
		{
			return ((volatile uint32_t*)(m_base + u32Offset));
		};

		inline void setRegValue(uint32_t u32Offset, uint32_t u32Value)
		{
			*getRegAddr(u32Offset) = u32Value;
		};

		inline void setRegField(uint32_t u32Offset, uint32_t u32Mask, uint32_t u32Value)
		{
			*getRegAddr(u32Offset) &= ~u32Mask;
			*getRegAddr(u32Offset) |= u32Value;
		}

		inline void setRegBit(uint32_t u32Offset, uint32_t u32Value)
		{
			*getRegAddr(u32Offset) |= u32Value;
		}

		inline uint32_t getRegField(uint32_t u32Offset, uint32_t u32Mask)
		{
			return (u32Mask & (*getRegAddr(u32Offset)));
		}

		inline void clearRegBit(uint32_t u32Offset, uint32_t u32Value)
		{
			*getRegAddr(u32Offset) &= ~u32Value;
		}

		inline uint32_t getRegValue(uint32_t u32Offset)
		{
			return ((uint32_t)*getRegAddr(u32Offset));
		};
	public:
		Peripheral(uint32_t base);
		virtual ~Peripheral();
};

} /* namespace lib */

#endif /* PERIPHERALS_PERIPHERAL_HH_ */
