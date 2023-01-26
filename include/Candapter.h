/******************************************************************************
 * @file   Candapter.h
 * @author George Peppard (@inventor02, gjp1g21@soton.ac.uk)
 * @brief  CANdapter driver header file
 *****************************************************************************/

#include <cstdint>
#include <mutex>
#include <string>
#include <thread>

#include "boost/asio.hpp"

namespace candapter {
class Candapter {
private:
  boost::asio::io_service io;
  boost::asio::serial_port port;

  std::string device;
  uint8_t baud;

public:
  Candapter(std::string device, uint8_t baud_rate);
};
}; // namespace candapter