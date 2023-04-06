#ifndef EthHttpClient_h
#define EthHttpClient_h

#include "Arduino.h"
#include <Ethernet.h>
class EthHttpClient{
  public:
    EthHttpClient(IPAddress server, EthernetClient client, String defaultPath);
    void Post(String path, String jsonBody);
    void Put(String path, String jsonBody);
    void Get(String path, String jsonBody);
    
  private:
    String _defaultPath;
    EthernetClient _client;
    IPAddress _server;
    void SendRequest(String Method, String path, String jsonBody);
};

#endif
