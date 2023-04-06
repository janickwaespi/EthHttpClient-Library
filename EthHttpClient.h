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
    //void Get(String path);
  private:
    String _defaultPath;
    EthernetClient _client;
    IPAddress _server;
};


//Put(string path, string jsonBody);
//string Get(string path, string jsonBody);

#endif
