/******************************************************************
 * uartport.cc
 *
 *  Created on: Jan 16, 2016
 *      Author: root
 ******************************************************************/

#include "stdbool.h"
#include "stdint.h"
#include "uart.hh"

namespace lib
{



uart::uart(uint32_t uart_base):
		m_uart_base(uart_base),
		m_uartdr(uart_base + UARTDR)
{
	// TODO Auto-generated constructor stub
	m_tx_buffer.length = 0;
	m_tx_buffer.current_idx = 0;
	m_rx_buffer.length = 0;
	m_rx_buffer.current_idx = 0;

}

uart::~uart()
{
	// TODO Auto-generated destructor stub
}
} /* namespace lib */


