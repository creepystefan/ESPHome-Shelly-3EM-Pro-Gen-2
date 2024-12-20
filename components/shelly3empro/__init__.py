import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import (CONF_ID)

shelly3empro_ns = cg.esphome_ns.namespace("shelly3empro")
Shelly3EMPRO = shelly3empro_ns.class_("Shelly3EMPRO", cg.PollingComponent)


CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(Shelly3EMPRO),
               
    }
).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
   var = cg.new_Pvariable(config[CONF_ID])
   await cg.register_component(var, config)
