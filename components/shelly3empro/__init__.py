import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor, modbus
from esphome.const import (
    CONF_ID,
    DEVICE_CLASS_VOLTAGE,
    DEVICE_CLASS_CURRENT,
    DEVICE_CLASS_POWER,
    ICON_CURRENT_AC,
    STATE_CLASS_MEASUREMENT,
    STATE_CLASS_TOTAL_INCREASING,
    UNIT_AMPERE,
    UNIT_HERTZ,
    UNIT_VOLT,
    UNIT_VOLT_AMPS,
    UNIT_VOLT_AMPS_REACTIVE,
    UNIT_WATT,
    CONF_ADDRESS,
)

#AUTO_LOAD = ["http_request"]
CODEOWNERS = ["@creepystefan"]

CONF_A_Voltage = "a_voltage"

UNIT_KILOWATT_HOURS = "kWh"
UNIT_KILOVOLT_AMPS_HOURS = "kVAh"
UNIT_KILOVOLT_AMPS_REACTIVE_HOURS = "kVARh"
UNIT_MODEL = "Model"
UNIT_SOFTWARE_VERSION = "Version"

shelly3em_ns = cg.esphome_ns.namespace("shelly3em")
Shelly3emSensor = shelly3em_ns.class_(
    "Shelly3emSensor", cg.PollingComponent
)

SENSORS = {
    CONF_A_voltage: sensor.sensor_schema(
        unit_of_measurement=UNIT_VOLT,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_VOLTAGE,
        state_class=STATE_CLASS_MEASUREMENT,
    ), 
    CONF_B_voltage: sensor.sensor_schema(
        unit_of_measurement=UNIT_VOLT,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_VOLTAGE,
        state_class=STATE_CLASS_MEASUREMENT,
    ), 
}

CONFIG_SCHEMA = (
    cv.Schema({cv.GenerateID(): cv.declare_id(Shelly3emSensor)})
    .extend(
        {cv.Optional(sensor_name): schema for sensor_name, schema in SENSORS.items()}
    )
    .extend(cv.polling_component_schema("1s"))
    )

async def to_code(config):
    cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    
    for name in SENSORS:
        if name in config:
            sens = await sensor.new_sensor(config[name])
            cg.add(getattr(var, f"set_{name}_sensor")(sens))
