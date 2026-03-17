#pragma once
#include <Arduino.h>

#define MLLSC_LOG(level,...) if (MLLServoConfigurator::LogLevel>=level) Serial.printf(__VA_ARGS__);

class MLLServoConfigurator
{
public:
  static uint8_t LogLevel;
};
