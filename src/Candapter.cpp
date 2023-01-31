/******************************************************************************
 * @file   Candapter.cpp
 * @author George Peppard (@inventor02, gjp1g21@soton.ac.uk)
 * @brief  Main CANdapter driver entry point
 *****************************************************************************/

#include "Candapter.h"

#include <cstdint>
#include <mutex>
#include <string>
#include <thread>

#include "boost/asio.hpp"

using candapter::Candapter;

Candapter::Candapter(std::string device, uint8_t baud_rate)
    : io(), device(device), baud(baud_rate), port(io, device) {
  port.set_option(boost::asio::serial_port_base::baud_rate(baud));
}