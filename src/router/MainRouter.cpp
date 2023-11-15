#include <Arduino.h>
#include <SPIFFS.h>
#include "MainRouter.h"
#include "../Settings.h"
#include <unordered_map>

std::unordered_map<std::string, std::string> _MainRouter::pageChart;

_MainRouter::_MainRouter()
{
}

void _MainRouter::begin()
{
    server.on("/", HTTP_GET, handleRootDirectoryRequest);
}

void _MainRouter::handleRootDirectoryRequest(AsyncWebServerRequest *request)
{
    request->redirect("http://192.168.4.1/api/resource?page=s");
}

_MainRouter MainRouter;