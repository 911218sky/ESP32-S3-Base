#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

#include "Settings.h"

#include "./router/resource/ResourceRouter.h"
#include "./router/obtain/ObtainRouter.h"
#include "./router/MainRouter.h"

#include "./utensil/QRcodeUtensil.h"
#include "./utensil/JsonFileManager.h"

AsyncWebServer server(80);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup()
{
    Serial.begin(115200);
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
    Wire.begin(SDA_PIN, SCL_PIN);
    // 檢查是否有螢幕
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR))
    {
        Serial.println(F("SSD1306 allocation failed"));
    }
    else
    {
        // 清空顯示
        display.clearDisplay();
        QRcodeUtensil.draw(QRCODR_URL);
    }

    // 启用热点模式sad
    WiFi.softAP(APSSID, APPASSWORD);

    // 初始化 SPIFFS
    SPIFFS.begin();

    // 引入 router
    MainRouter.begin();
    ResourceRouter.begin();
    ObtainRouter.begin();

    server.begin();

    printSpace();
    printWifiInformation();

    // DynamicJsonDocument doc(512);

    // doc["phoneNumber"] = "0912345";
    // JsonFileManager.writeJson(SETTING_FILE, doc);
}

void scanAP(void)
{
    int n = WiFi.scanNetworks();
    delay(1000);
    Serial.println("scan Wi-Fi done");
    if (n == 0)
        Serial.println("no Wi-Fi networks found");
    else
    {
        Serial.print(n);
        Serial.println(" Wi-Fi networks found");
        for (int i = 0; i < n; ++i)
        {
            Serial.print(i + 1);
            Serial.print(": ");
            // 印出SSID
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            // 印出RSSI強度
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            // 印出加密模式
            Serial.println(WiFi.encryptionType(i), HEX);
            delay(10);
        }
    }
}

void loop()
{
    // scanAP();
    // delay(1000);
    // delay(1000);
    // DynamicJsonDocument doc(512);
    // JsonFileManager.readJson(SETTING_FILE, doc);
    // Serial.println("phoneNumber : " + doc["phoneNumber"].as<String>());
}