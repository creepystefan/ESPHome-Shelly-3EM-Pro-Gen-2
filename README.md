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
    name: A-Voltage
    host: ${ShellyIP}
    register_address: 1021
    accuracy_decimals: 2

  - platform: shelly3empro2modbus
    name: B-Voltage
    host: ${ShellyIP}
    register_address: 1041
    accuracy_decimals: 2

  - platform: shelly3empro2modbus
    name: C-Voltage
    host: ${ShellyIP}
    register_address: 1061
    accuracy_decimals: 2

  - platform: shelly3empro2modbus
    name: "total active Power"
    host: ${ShellyIP}
    register_address: 1014
    accuracy_decimals: 2
```




# helpful link
https://loxwiki.atlassian.net/wiki/spaces/LOX/pages/1618182667/Shelly+Pro+per+UDP
https://shelly-api-docs.shelly.cloud/gen2/ComponentsAndServices/Modbus/
https://shelly-api-docs.shelly.cloud/gen2/ComponentsAndServices/EM/#modbus-registers
https://shelly-api-docs.shelly.cloud/gen2/ComponentsAndServices/EMData/#modbus-registers

