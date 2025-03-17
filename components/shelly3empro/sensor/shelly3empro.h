#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"


namespace esphome {
namespace shelly3em {

#define SHELLY3EM_SENSOR(name) \
 protected: \
  sensor::Sensor *name##_sensor_{nullptr}; \
\
 public: \
  void set_##name##_sensor(sensor::Sensor *(name)) { this->name##_sensor_ = name; }

class Shelly3emSensor : public PollingComponent {
 public:
  SHELLY3EM_SENSOR(a_voltage)
  SHELLY3EM_SENSOR(b_voltage)
  
  
  void update() override;
 
  void dump_config() override;
};

}  // namespace xy6020
}  // namespace esphome
