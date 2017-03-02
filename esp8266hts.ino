#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>
#include <DHT.h>
#define USE_SERIAL Serial
#define DHTTYPE DHT11   // if the sensor is DHT11 or DHT22 
#define DHTPIN 2     // what digital pin we're connected to the temperature and humidity sensor
  const int gasPin = A0; //GAS sensor output pin to Arduino analog A0 pin
  
  // you need to change the follwing values
  const char* ssid = "SSID";
  const char* password = "SSIDPASS";
  const char* iotid = "ID";
   const char* servaddress = "IPORDOMAIN";
   // end change
   
  DHT dht(DHTPIN, DHTTYPE);

ESP8266WiFiMulti WiFiMulti;

void setup() {

    USE_SERIAL.begin(115200);
   // USE_SERIAL.setDebugOutput(true);
    dht.begin(); // start our tempretature and humidity sensor
    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println();

// try to connect to wifi
    for(uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
        USE_SERIAL.flush();
        delay(1000);
    }

// give the ssid and password parameters for the wifi connection
    WiFiMulti.addAP(ssid, password);

}

void loop() {
    // wait for WiFi connection if connected proceed to upload the values
    if((WiFiMulti.run() == WL_CONNECTED)) {
   USE_SERIAL.printf("Connected To WIFI...\n");
// read humidity 
  float h = dht.readHumidity();
 // read temperature
 float t = dht.readTemperature();
 // read gas
 float gs = analogRead(gasPin);

   // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)|| isnan(gs)) {
    Serial.println("Failed to read sensors!");
    return;
  }
 

        HTTPClient http;

        USE_SERIAL.print("[HTTP] begin...\n");
        // configure traged server and url
    http.begin("http://" + String(servaddress) + "/gettemperature.php?id=" + String(iotid) + "&temp=" + String(t) + "&hum=" + String(h)+ "&gas=" + String(gs)); //HTTP request
        USE_SERIAL.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                USE_SERIAL.println(payload);
            }
        } else {
            USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
    }

    delay(300000);
}
