#include <Arduino.h>
#include <ArduinoJson.h>
//#include <ESP8266WiFi.h>
//#include <ESP8266WiFiMulti.h>
//#include <ESP8266HTTPClient.h>
//#include <WiFiClient.h>
//#include "wlan.h"
#pragma once

#include "esphome/core/component.h"
#include "esphome.h"

namespace esphome {
namespace shelly3empro { 

class Shelly3EMPRO : public PollingComponent {
 public:
  Shelly3EMPRO() : PollingComponent(10) {}

//#define PIN        4 
//#define NUMPIXELS 19 
//const char * steht im wlan.h
//const char * steht im wlan.h

String Shelly_IP = "192.168.178.22";

int http_get(String getstr, int t)
{
 
  DynamicJsonDocument doc(2048);

  WiFiClient client;
  HTTPClient http;
  int pwr, pwt ;

  if (t == 1) { getstr = "http://" + Shelly_IP +  "/rpc/Shelly.GetStatus" ; }   // Shelly PRO 3EM 
  else {        getstr = "http://" + Shelly_IP + "/status" ; }                  // Shelly EM, 1PM, 3PM
  
  if (http.begin(client,getstr)) 
  {  
    int httpCode = http.GET();         
    if (httpCode > 0) 
    {
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
      {
        String payload = http.getString();
        //Serial.println(payload);
        DeserializationError error = deserializeJson(doc, payload);
        if (DEBUG) {serializeJsonPretty(doc, Serial); } // nur Debug
        
        if (error) 
        {
          if (DEBUG) {
          Serial.print(F("deserializeJson() failed: "));
          Serial.println(error.f_str());}
           pwr = -99999;
        } else {
          pwr = doc["total_power"] ;                              // Shelly 1PM
          pwt = doc["meters"]["0"]["power"]  ; pwr = pwr + pwt ;  // Shelly EM
          pwt = doc["emeters"]["0"]["power"] ; pwr = pwr + pwt ;  // Shelly 3EM  
          pwt = doc["em:0"]["total_act_power"];pwr = pwr + pwt ;  // Shelly PRO 3EM 
        } 
    } else {
      if (DEBUG) {Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());}
       pwr = -99999;
    }  
    http.end();
  } else {      
    pwr = -99999;   
    if (DEBUG) {Serial.printf("[HTTP} Unable to connect\n");}
  }  
  } else {      
    pwr = -99999;  }
  return pwr;
}
// wenn die Wattzahl -99999 ergibt liegt ein Fehler vor oder es werden 100kW eingespeist
// Ende Funktion  

};

}  // namespace shelly3empro
}  // namespace esphome
