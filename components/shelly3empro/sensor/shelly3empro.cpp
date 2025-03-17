#include "shelly3empro.h"
#include "esphome/core/log.h"

namespace esphome {
namespace shelly3em {

static const char *const TAG = "Shelly3EMPro";
 


void XY6020Sensor::dump_config() {
  ESP_LOGCONFIG(TAG, "Shelly Sensor:");
  
  LOG_SENSOR("  ", "a-Voltage", this->model_sensor_);
  LOG_SENSOR("  ", "b-Voltage", this->software_version_sensor_);  
}

}  // namespace shelly3em
}  // namespace esphome
