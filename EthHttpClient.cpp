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
void EthHttpClient::Post(String path, String jsonBody){ 
  // connect to server
  if (_client.connect(_server, 80)) { 
    // http Post protocol
    _client.println("POST " + _defaultPath + path + " HTTP/1.1");
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
  // receive API feedback
  while (_client.connected()) {
    if (_client.available()) {
      char c = _client.read();
      Serial.print(c);
    }
  }
  // disconnect from server
  Serial.println("Disconnected from server");
  _client.stop();
}
// ---------------------------------------------------------
// Put request
// ---------------------------------------------------------
void EthHttpClient::Put(String path, String jsonBody){ 
  // connect to server
  if (_client.connect(_server, 80)) { 
    // http Post protocol
    _client.println("PUT " + _defaultPath + path + " HTTP/1.1");
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
  // receive API feedback
  while (_client.connected()) {
    if (_client.available()) {
      char c = _client.read();
      Serial.print(c);
    }
  }
  // disconnect from server
  Serial.println("Disconnected from server");
  _client.stop();
}
// ---------------------------------------------------------
// Put request
// ---------------------------------------------------------
/*void EthHttpClient::Get(String path){ 
  String jsonBody = "{}";
  // connect to server
  if (_client.connect(_server, 80)) { 
    // http Post protocol
    _client.println("Get " + _defaultPath + path + " HTTP/1.1");
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
  // receive API feedback
  while (_client.connected()) {
    if (_client.available()) {
      char c = _client.read();
      Serial.print(c);
    }
  }
  // disconnect from server
  Serial.println("Disconnected from server");
  _client.stop();
}*/
// ---------------------------------------------------------
// Put request
// ---------------------------------------------------------
void EthHttpClient::Get(String path, String jsonBody){ 
  // connect to server
  if (_client.connect(_server, 80)) { 
    // http Post protocol
    _client.println("GET " + _defaultPath + path + " HTTP/1.1");
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
  // receive API feedback
  while (_client.connected()) {
    if (_client.available()) {
      char c = _client.read();
      Serial.print(c);
    }
  }
  // disconnect from server
  Serial.println("/nDisconnected from server");
  _client.stop();
}
