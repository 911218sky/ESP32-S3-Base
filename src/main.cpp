#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include "Settings.h"
#include "./router/resource/RouterResource.h"
#include "./router/MainRouter.h"
#include "./utensil/QRcodeUtensil.h"

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

    // 启用热点模式
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
}

void loop()
{
    // 获取连接到热点的设备数量
    int numStations = WiFi.softAPgetStationNum();

    // 打印连接设备的数量
    Serial.print("Number of connected stations: ");
    Serial.println(numStations);

    delay(5000); // 每隔5秒打印一次
}
