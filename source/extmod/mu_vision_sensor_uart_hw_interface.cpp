/*
 * mu_vision_sensor_uart_hw_interface.cpp
 *
 *  Created on: 2018年8月8日
 *      Author: ysq
 */

#include "extmod/mu_vision_sensor_uart_hw_interface.h"
#include <ErrorNo.h>

MuVisionSensorUart::MuVisionSensorUart(MuVsUart* uart,
                                       uint32_t address)
    : MuVsUartMethod(address),
      uart_(uart) {
}

MuVisionSensorUart::~MuVisionSensorUart() {}

uint32_t MuVisionSensorUart::UartRead(uint8_t* temp, uint8_t length) {
  int ret = uart_->read(temp, length);
  if(ret == MICROBIT_SERIAL_IN_USE) {
    return 0;
  }
  return ret;
}

uint32_t MuVisionSensorUart::UartWrite(uint8_t* temp, uint8_t length) {
  int ret = uart_->send(temp, length);
  if(ret == MICROBIT_SERIAL_IN_USE) {
    return 0;
  }
  return ret;
}

