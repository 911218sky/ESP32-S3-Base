#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#define APSSID "ESP32-S3-AP"
#define APPASSWORD "12345678"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C

#define SCL_PIN 21
#define SDA_PIN 20

#define IP_ADDRESS "192.168.4.1"
#define QRCODR_URL ("http://" + std::string(IP_ADDRESS)).c_str()

#define SETTING_FILE "/SETTING.json"

#ifndef _ESPAsyncWebServer_H_
#include <ESPAsyncWebServer.h>
#endif

#ifndef _SPI_H_INCLUDED
#include <SPI.h>
#endif

#ifndef TwoWire_h
#include <Wire.h>
#endif

#ifndef _ADAFRUIT_GFX_H
#include <Adafruit_GFX.h>
#endif

#ifndef _Adafruit_SSD1306_H_
#include <Adafruit_SSD1306.h>
#endif

class _Settings;

extern AsyncWebServer server;
extern Adafruit_SSD1306 display;

void printSpace();
void printWifiInformation();

#endif