#include <Arduino.h>
#include "webServer/wifiUpdate/webServer.h"

WebServerModule webServerModule;

void setup() {
  Serial.begin(115200);
  if(WIFI_UPDATE_ENABLED) webServerModule.begin();
}

void loop() {
  if(WIFI_UPDATE_ENABLED) webServerModule.handleClient();
}