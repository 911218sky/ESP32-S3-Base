// #include <Arduino.h>
// #include <SPIFFS.h>
// #include "RouterResource.h"
// #include "../../Settings.h"
// #include <unordered_map>

// std::unordered_map<std::string, std::string> _RouterResource::pageChart;

// _RouterResource::_RouterResource()
// {
//     pageChart["s"] = "/Settings.html";
//     pageChart["w"] = "/Wifi.html";
// }

// void _RouterResource::begin()
// {
//     server.on("/api/resource", HTTP_GET, handleHTMLResourceRequest);
// }

// void _RouterResource::handleHTMLResourceRequest(AsyncWebServerRequest *request)
// {
//     if (!request->hasParam("page"))
//     {
//         request->send(400, "text/plain", "Error: 'page' parameter is missing");
//         return;
//     }

//     AsyncWebParameter *parame = request->getParam("page");
//     std::string page = std::string(parame->value().c_str());

//     if (pageChart.find(page) == pageChart.end())
//     {
//         request->send(400, "text/plain", "Error: 'page' parameter is missing");
//         return;
//     }

//     File file = SPIFFS.open(pageChart[page].c_str(), "r");

//     if (file)
//     {
//         String content = file.readString();
//         file.close();
//         request->send(200, "text/html", content);
//     }
//     else
//     {
//         request->send(404, "text/plain", "Page not found");
//     }
// }

// _RouterResource RouterResource;
