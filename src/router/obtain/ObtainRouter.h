#ifndef _OBTAIN_ROUTER_H_
#define _OBTAIN_ROUTER_H_

class _ObtainRouter;

#ifndef _ESPAsyncWebServer_H_
#include <ESPAsyncWebServer.h>
#endif

class _ObtainRouter
{
private:
    // static void handleResourceRequest(AsyncWebServerRequest *);
    static void getWifiInformation(AsyncWebServerRequest *);

public:
    _ObtainRouter();
    void begin();
};

extern _ObtainRouter ObtainRouter;

#endif
