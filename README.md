# ESPHome-Shelly-HTTP-Request


# ESPhome - Shelly 3EM Pro Gen2 Modbus TCP Sensor

# External Component
```yaml
external_components:
  - source: github://creepystefan/ESPHome-Shelly-3EM-Pro-Gen-2
    refresh: 0s
```

# Example
```yaml
substitutions:
  ShellyIP: "192.168.178.46" 
  
sensor:
  - platform: shelly3empro2modbus
    name: "total active Power"
    host: ${ShellyIP}
    register_address: 1014
    accuracy_decimals: 2
    unit_of_measurement: "W"

  # Phase A

  - platform: shelly3empro2modbus
    name: "A-Voltage"
    host: ${ShellyIP}
    register_address: 1021
    accuracy_decimals: 2
    unit_of_measurement: "V"

  - platform: shelly3empro2modbus
    name: "A-Current"
    host: ${ShellyIP}
    register_address: 1023
    accuracy_decimals: 2
    unit_of_measurement: "A"

  - platform: shelly3empro2modbus
    name: "A-Power"
    host: ${ShellyIP}
    register_address: 1025
    accuracy_decimals: 2
    unit_of_measurement: "W"

  - platform: shelly3empro2modbus
    name: "A-frequency"
    host: ${ShellyIP}
    register_address: 1034
    accuracy_decimals: 2
    unit_of_measurement: "Hz"

# Phase B

  - platform: shelly3empro2modbus
    name: "B-Voltage"
    host: ${ShellyIP}
    register_address: 1041
    accuracy_decimals: 2
    unit_of_measurement: "V"

  - platform: shelly3empro2modbus
    name: "B-Current"
    host: ${ShellyIP}
    register_address: 1043
    accuracy_decimals: 2
    unit_of_measurement: "A"

  - platform: shelly3empro2modbus
    name: "B-Power"
    host: ${ShellyIP}
    register_address: 1045
    accuracy_decimals: 2
    unit_of_measurement: "W"

  - platform: shelly3empro2modbus
    name: "B-frequency"
    host: ${ShellyIP}
    register_address: 1054
    accuracy_decimals: 2
    unit_of_measurement: "Hz"

  # Phase C

  - platform: shelly3empro2modbus
    name: "C-Voltage"
    host: ${ShellyIP}
    register_address: 1061
    accuracy_decimals: 2
    unit_of_measurement: "V"

  - platform: shelly3empro2modbus
    name: "C-Current"
    host: ${ShellyIP}
    register_address: 1063
    accuracy_decimals: 2
    unit_of_measurement: "A"

  - platform: shelly3empro2modbus
    name: "C-Power"
    host: ${ShellyIP}
    register_address: 1065
    accuracy_decimals: 2
    unit_of_measurement: "W"

  - platform: shelly3empro2modbus
    name: "C-frequency"
    host: ${ShellyIP}
    register_address: 1074
    accuracy_decimals: 2
    unit_of_measurement: "Hz"
    accuracy_decimals: 2
```




# helpful link
https://loxwiki.atlassian.net/wiki/spaces/LOX/pages/1618182667/Shelly+Pro+per+UDP
https://shelly-api-docs.shelly.cloud/gen2/ComponentsAndServices/Modbus/
https://shelly-api-docs.shelly.cloud/gen2/ComponentsAndServices/EM/#modbus-registers
https://shelly-api-docs.shelly.cloud/gen2/ComponentsAndServices/EMData/#modbus-registers

