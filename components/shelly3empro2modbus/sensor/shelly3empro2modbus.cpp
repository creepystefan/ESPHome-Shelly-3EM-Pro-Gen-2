#include "shelly3empro2modbus.h"
#include "esphome/core/log.h"

namespace esphome {
namespace shelly3empro2modbus {

static const char *const TAG = "ShellyModbus";



void ShellyModbus::update() {
WiFiClient client;
    if (!client.connect(host_.c_str(), 502)) {
      ESP_LOGE("shelly3empro2modbus", "Failed to connect to Shelly 3EM Pro %s:%d", host_.c_str(), 502);
      return;
    }

  uint8_t request[] = {
        0x00, 0x08, 0x00, 0x00, 0x00, 0x06, 0x01, 0x04,
        (uint8_t)((register_address_ >> 8) & 0xFF),
        (uint8_t)(register_address_ & 0xFF),
        0x00, 0x02
        };
    ESP_LOGD("TX", "Address: %d >>>> %02X%02X %02X%02X %02X%02X %02X %02X %02X%02X %02X%02X",
                        this->register_address_,
                        request[0], request[1], request[2], request[3], request[4]
                        , request[5], request[6], request[7], request[8]
                        , request[9], request[10], request[11]
                        );

client.write(request, sizeof(request));
delay(100);

uint8_t response[256];
    size_t response_len = client.read(response, sizeof(response));

if (response[7] != request[7]) {
      ESP_LOGE("modbus_tcp", "Unexpected function code: 0x%02X", response[7]);
      return;
    }

if (response[1] != request[1]) {
      ESP_LOGE("modbus_tcp", "Unexpected Transaction ID: 0x%02X", response[1]);
      return;
    }

 
    ESP_LOGD("RX", "Address: %d <<<< %02X%02X %02X%02X %02X%02X %02X %02X %02X %02X%02X%02X%02X ",
                      this->register_address_,
                      response[0], response[1], response[2], response[3], response[4], 
                      response[5], response[6], response[7], response[8], response[9], 
                      response[10], response[11], response[12] 
                      );


float value = decode_float(&response[9]);
publish_state(value);
}


void ShellyModbus::dump_config() {
  ESP_LOGCONFIG(TAG, "Address: %d", this->register_address_);
}

}  // namespace modbus_tcp_float
}  // namespace esphome