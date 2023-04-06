#ifndef EthHttpClient_h
#define EthHttpClient_h

#include "Arduino.h"
#include <Ethernet.h>


class EthHttpClient{
  public:
    EthHttpClient(String defaultPath, EthernetClient client);
    void Post(String path, String jsonBody);
  private:
    String _defaultPath;
    EthernetClient _client;
};


//Put(string path, string jsonBody);
//string Get(string path, string jsonBody);

#endif
