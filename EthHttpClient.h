#ifndef EthHttpClient_h
#define EthHttpClient_h

#include "Arduino.h"
#include <Ethernet.h>
class EthHttpClient{
  public:
    EthHttpClient(IPAddress server, EthernetClient client, String defaultPath);
    String Post(String path, String jsonBody);
    String Put(String path, String jsonBody);
    String Get(String path, String jsonBody);
    String Delete(String path, String jsonBody);
  private:
    String _defaultPath;
    EthernetClient _client;
    IPAddress _server;
    String SendRequest(String method, String path, String jsonBody);
};

#endif
