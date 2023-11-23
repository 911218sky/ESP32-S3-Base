// #include <Arduino.h>
// #include <WiFi.h>
// #include <ESPAsyncWebServer.h>
// #include <SPIFFS.h>
// #include "Settings.h"
// #include "./router/resource/RouterResource.h"
// #include "./router/MainRouter.h"
// #include "./utensil/QRcodeUtensil.h"
// #include "./utensil/JsonFileManager.h"

// AsyncWebServer server(80);
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// void setup()
// {
//   Serial.begin(115200);

//   // 启用热点模式sad
//   WiFi.softAP(APSSID, APPASSWORD);

//   // 初始化 SPIFFS
//   SPIFFS.begin(true);
//   server.onNotFound([](AsyncWebServerRequest *request)
//                     {
//     String path = request->url();

//     if (path == "/") {
//       path = "/dist/index.html.gz";
//     } else {
//       path = "/dist" + path + ".gz";
//     }
//     Serial.println(path);
//     if (SPIFFS.exists(path)) {
//       AsyncWebServerResponse *response = request->beginResponse(SPIFFS, path, "text/html");
//       response->addHeader("Content-Encoding", "gzip");
//       request->send(response);
//     } else {
//       // Handle 404 Not Found
//       request->send(404, "text/plain", "File not found");
//     } });

//   server.begin();
//   Serial.println("Access Point Started");
//   Serial.print("IP Address: ");
//   Serial.println(WiFi.softAPIP());

//   unsigned int totalBytes = SPIFFS.totalBytes();
//   unsigned int usedBytes = SPIFFS.usedBytes();

//   unsigned int totalKilobytes = totalBytes / 1024;
//   unsigned int usedKilobytes = usedBytes / 1024;
//   unsigned int freeKilobytes = (totalBytes - usedBytes) / 1024;

//   Serial.print("Total space (KB): ");
//   Serial.println(totalKilobytes);
//   Serial.print("Used space (KB): ");
//   Serial.println(usedKilobytes);
//   Serial.print("Free space (KB): ");
//   Serial.println(freeKilobytes);
// }

// void loop()
// {
// }

