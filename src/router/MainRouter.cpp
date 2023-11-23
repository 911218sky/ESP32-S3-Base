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

    request->redirect("http://" + String(IP_ADDRESS) + "/resource/index");
}

_MainRouter MainRouter;