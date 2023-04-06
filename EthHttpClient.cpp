#include "Arduino.h"
#include "EthHttpClient.h"
#include <SPI.h>
#include <Ethernet.h>

EthHttpClient::EthHttpClient(String defaultPath, EthernetClient client){
  _defaultPath = defaultPath;
  _client = client;
}

void EthHttpClient::Post(String path, String jsonBody){

  delay(1000);
  Serial.println(path);
  Serial.println(jsonBody);

}