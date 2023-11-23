#include <Arduino.h>
#include <SPIFFS.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <string>
#include "ObtainRouter.h"
#include "../../Settings.h"

_ObtainRouter::_ObtainRouter()
{
}

void _ObtainRouter::begin()
{
    server.on("/obtain", HTTP_GET, getWifiInformation);
}

void _ObtainRouter::getWifiInformation(AsyncWebServerRequest *request)
{
    DynamicJsonDocument doc(1024);
    int n = WiFi.scanComplete();
    Serial.println(n);
    if (n == -2)
    {
        WiFi.scanNetworks(true);
    }
    else if (n)
    {
        JsonArray networks = doc.createNestedArray("networks");
        for (int i = 0; i < n; ++i)
        {
            JsonObject network = networks.createNestedObject();
            network["rssi"] = WiFi.RSSI(i);
            network["ssid"] = WiFi.SSID(i);
            network["bssid"] = WiFi.BSSIDstr(i);
            network["channel"] = WiFi.channel(i);
            network["secure"] = WiFi.encryptionType(i);
            delay(10);
        }
        WiFi.scanDelete();
        if (WiFi.scanComplete() == -2)
        {
            WiFi.scanNetworks(true);
        }
    }

    String json;
    serializeJson(doc, json);
    request->send(200, "application/json", json);
}

_ObtainRouter ObtainRouter;
