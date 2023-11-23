#ifndef _RESOURCE_ROUTER_H_
#define _RESOURCE_ROUTER_H_

class _ResourceRouter;

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

class _ResourceRouter
{
private:
    static std::unordered_map<std::string, std::string> pageChart;
    static void handleResourceRequest(AsyncWebServerRequest *);
public:
    _ResourceRouter();
    void begin();
};

extern _ResourceRouter ResourceRouter;

#endif
