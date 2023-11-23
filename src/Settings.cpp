
#include <Arduino.h>
#include <SPIFFS.h>
#include <WiFi.h>
#include "Settings.h"

void printSpace()
{
    unsigned int totalBytes = SPIFFS.totalBytes();
    unsigned int usedBytes = SPIFFS.usedBytes();

    unsigned int totalKilobytes = totalBytes / 1024;
    unsigned int usedKilobytes = usedBytes / 1024;
    unsigned int freeKilobytes = (totalBytes - usedBytes) / 1024;

    Serial.print("Total space (KB): ");
    Serial.println(totalKilobytes);
    Serial.print("Used space (KB): ");
    Serial.println(usedKilobytes);
    Serial.print("Free space (KB): ");
    Serial.println(freeKilobytes);
}

void printWifiInformation()
{
    Serial.print("IP Address: ");
    Serial.println(WiFi.softAPIP());
}