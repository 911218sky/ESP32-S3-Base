#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include "Settings.h"
#include "./router/resource/RouterResource.h"
#include "./router/MainRouter.h"
#include "./utensil/QRcodeUtensil.h"
#include "./utensil/JsonFileManager.h"

AsyncWebServer server(80);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup()
{
    Serial.begin(115200);

    Wire.begin(SDA_PIN, SCL_PIN);
    // 檢查是否有螢幕
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR))
    {
        Serial.println(F("SSD1306 allocation failed"));
    }

    // 清空顯示
    display.clearDisplay();
    QRcodeUtensil.draw(QRCODR_URL);

    // 启用热点模式sad
    WiFi.softAP(APSSID, APPASSWORD);

    // 初始化 SPIFFS
    SPIFFS.begin();

    // 引入 router
    MainRouter.begin();
    RouterResource.begin();

    server.begin();
    Serial.println("Access Point Started");
    Serial.print("IP Address: ");
    Serial.println(WiFi.softAPIP());

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

    DynamicJsonDocument doc(512);

    doc["phoneNumber"] = "0912345";
    JsonFileManager.writeJson(SETTING_FILE, doc);
}

void loop()
{
    delay(1000);
    DynamicJsonDocument doc(512);
    JsonFileManager.readJson(SETTING_FILE, doc);
    Serial.println("phoneNumber : " + doc["phoneNumber"].as<String>());
}