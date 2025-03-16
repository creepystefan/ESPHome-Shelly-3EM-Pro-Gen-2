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
  SHELLY3EM_SENSOR(A_voltage)
  SHELLY3EM_SENSOR(B_voltage)
  
  
  void update() override;
 

  //void on_modbus_data(const std::vector<uint8_t> &data) override;

  void dump_config() override;
};

}  // namespace xy6020
}  // namespace esphome
