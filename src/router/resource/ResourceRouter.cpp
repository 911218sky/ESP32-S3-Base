#include <Arduino.h>
#include <SPIFFS.h>
#include "ResourceRouter.h"
#include "../../Settings.h"
#include <unordered_map>

_ResourceRouter::_ResourceRouter()
{
}

void _ResourceRouter::begin()
{
    server.on("/resource", HTTP_GET, handleResourceRequest);
}

void _ResourceRouter::handleResourceRequest(AsyncWebServerRequest *request)
{
    String path = request->url();
    int resourceStart = path.lastIndexOf('/');
    path = path.substring(resourceStart + 1);

    if (path == "index")
    {
        path = "/dist/index.html.gz";
    }
    else
    {
        path = "/dist/" + path + ".gz";
    }

    if (SPIFFS.exists(path))
    {
        AsyncWebServerResponse *response = request->beginResponse(SPIFFS, path, "text/html");
        response->addHeader("Content-Encoding", "gzip");
        request->send(response);
    }
    else
    {
        request->send(404, "text/plain", "File not found");
    }
}

_ResourceRouter ResourceRouter;
