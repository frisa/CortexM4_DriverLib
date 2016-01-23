/******************************************************************
 * uartport.hh
 *
 *  Created on: Jan 16, 2016
 *      Author: root
 ******************************************************************/

#ifndef UARTPORT_HH_
#define UARTPORT_HH_

#include "stdbool.h"
#include "stdint.h"

namespace lib
{

/*******************************************************************
 *
 *******************************************************************/
class uart
{
		/* adresses of UART registers */
		enum enRegOffesets
		{
			UARTDR = 0x000,
		};
		const uint32_t m_uart_base;

		const uint32_t m_uartdr;

		struct uartBuffer
		{
				uint32_t length;
				uint32_t current_idx;
				uint8_t	* data;
		};
		uartBuffer m_tx_buffer;
		uartBuffer m_rx_buffer;

	public:
		uart(uint32_t uart_base);
    	virtual ~uart();
};

} /* namespace lib */

#endif /* UARTPORT_HH_ */
