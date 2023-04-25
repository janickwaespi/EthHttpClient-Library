#include "Arduino.h"
#include "EthHttpClient.h"
#include <SPI.h>
#include <Ethernet.h>
// ---------------------------------------------------------
// EthHttpClient constructor
// ---------------------------------------------------------
EthHttpClient::EthHttpClient(IPAddress server, EthernetClient client, String defaultPath){
  _defaultPath = defaultPath;   // default path added tp server url
  _client = client;             // Ethernet class object
  _server = server;             // server ip address
}
// ---------------------------------------------------------
// Post request
// ---------------------------------------------------------
String EthHttpClient::Post(String path, String jsonBody){ 
  return SendRequest("POST", path, jsonBody);
}
// ---------------------------------------------------------
// Put request
// ---------------------------------------------------------
String EthHttpClient::Put(String path, String jsonBody){ 
  return SendRequest("PUT", path, jsonBody);
}
// ---------------------------------------------------------
// Get request
// ---------------------------------------------------------
String EthHttpClient::Get(String path, String jsonBody){ 
  return SendRequest("GET", path, jsonBody);
}
// ---------------------------------------------------------
// Delete request
// ---------------------------------------------------------
String EthHttpClient::Delete(String path, String jsonBody){ 
  return SendRequest("DELETE", path, jsonBody);
}
// ---------------------------------------------------------
// Handles Post, Put and Get requests
// ---------------------------------------------------------
String EthHttpClient::SendRequest(String method, String path, String jsonBody){
  // connect to server
  if (_client.connect(_server, 80)) { 
    // http Post protocol
    _client.println(method + " " + _defaultPath + path + " HTTP/1.1");
    _client.println("Host: 10.0.2.109"); 
    _client.println("Content-Type: application/json");
    _client.print("Content-Length: ");
    _client.println(jsonBody.length());
    _client.println("Connection: close");
    _client.println();
    _client.println(jsonBody);
  } else {
    Serial.println("Connection failed");
  }
  // receive feedback
  String response = "";
  while (_client.connected()) {
    if (_client.available()) {
      char c = _client.read();
      Serial.print(c);
      response += c;
    }
  }
  // disconnect from server
  Serial.println("Disconnected from server");
  Serial.println("");
  _client.stop();
  delay(5);

  return response;
}
