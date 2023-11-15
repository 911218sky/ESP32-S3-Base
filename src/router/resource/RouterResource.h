#ifndef _ROUTER_RESOURCE_H_
#define _ROUTER_RESOURCE_H_

class _RouterResource;

#ifndef _ESPAsyncWebServer_H_
#include <ESPAsyncWebServer.h>
#endif

#ifndef _ESPAsyncWebServer_H_
#include <ESPAsyncWebServer.h>
#endif

#ifndef _GLIBCXX_UNORDERED_MAP
#include <unordered_map>
#endif

#ifndef _GLIBCXX_STRING
#include <string>
#endif

class _RouterResource
{
private:
    static std::unordered_map<std::string, std::string> pageChart;
    static void handleHTMLResourceRequest(AsyncWebServerRequest *);

public:
    _RouterResource();
    void begin();
};

extern _RouterResource RouterResource;

#endif
