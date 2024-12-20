//#include <Arduino.h>
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

WiFiClient client;
HTTPClient http;

class Shelly3EMPRO : public PollingComponent {
 public:
  Shelly3EMPRO() : PollingComponent(10) {}

//#define PIN        4 
//#define NUMPIXELS 19 
//const char * steht im wlan.h
//const char * steht im wlan.h

String Shelly_IP = "192.168.178.22";

ESP8266WiFiMulti WiFiMulti;


//const int led = LED_BUILTIN;

void setup() 
{
//  pinMode(led, OUTPUT);
//  digitalWrite(led, LOW);

//  Serial.begin(115200);

//  pinMode(PIN, OUTPUT);
 
  
//  Serial.println();

/*  for (uint8_t t = 4; t > 0; t--) 
//  {*/
//    Serial.printf("[SETUP] WAIT ...\n");
    Serial.flush();   Serial.println();
// /*   delay(1000);
//  }*/
//  WiFi.mode(WIFI_STA);
//  WiFiMulti.addAP(ssid, password);

 // digitalWrite(led, HIGH);
}

//int actled;
int pwr1;  //,pwr2,pwr3,pwrsum;

int http_get(String getstr)
{
  //StaticJsonDocument<2000> doc;
  
  DynamicJsonDocument doc(2048);
 

  //WiFiClient client;
  //HTTPClient http;
  int pwr;
   
  if (http.begin(client, getstr)) 
  {  
    int httpCode = http.GET();         
    if (httpCode > 0) 
    {
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
      {
        String payload = http.getString();
        //Serial.println(payload);
        DeserializationError error = deserializeJson(doc, payload);
        
        serializeJsonPretty(doc, Serial);  // nur Debug
        
        if (error) 
        {
          Serial.print(F("deserializeJson() failed: "));
          Serial.println(error.f_str());
        }
          pwr = doc["em:0"]["total_act_power"];
           
          
          //Serial.println();
          //Serial.print("Ergebnis: ");
          //Serial.println(pwr);
       
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
  } else {
    Serial.printf("[HTTP} Unable to connect\n");
  }
  return pwr;
}

void loop() 
{
  // wait for WiFi connection
  //if ((WiFiMulti.run() == WL_CONNECTED)) 
  //{
  //  digitalWrite(led, LOW);
    pwr1 = http_get("http://" + Shelly_IP + "/rpc/Shelly.GetStatus");
 
   // digitalWrite(led, HIGH);
  //}
       Serial.print("Ergebnis: ");
       Serial.println(pwr1);
  
  delay(5000);
}

};

}  // namespace shelly3empro
}  // namespace esphome
