#ifndef _MAIN_ROUTER_H_
#define _MAIN_ROUTER_H_

class _MainRouter;

#ifndef _ESPAsyncWebServer_H_
#include <ESPAsyncWebServer.h>
#endif

#ifndef _GLIBCXX_UNORDERED_MAP
#include <unordered_map>
#endif

#ifndef _GLIBCXX_STRING
#include <string>
#endif

class _MainRouter
{
private:
    static std::unordered_map<std::string, std::string> pageChart;
    static void handleRootDirectoryRequest(AsyncWebServerRequest *);

public:
    _MainRouter();
    void begin();
};

extern _MainRouter MainRouter;

#endif
