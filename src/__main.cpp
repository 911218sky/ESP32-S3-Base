// #include <ArduinoJson.h>
// #include <SPIFFS.h>

// // Our configuration structure.
// struct Config
// {
//     char hostname[64];
//     int port;
// };

// const char *filename = "/config.json"; // 文件名
// Config config;                         // 全局配置对象

// // 加载配置
// void loadConfiguration(const char *filename, Config &config)
// {
//     // 打开文件以供读取
//     File file = SPIFFS.open(filename, "r");

//     // 创建一个动态分配内存的 JsonDocument
//     DynamicJsonDocument doc(512);

//     // 从 JSON 文档中反序列化数据
//     DeserializationError error = deserializeJson(doc, file);
//     if (error)
//         Serial.println(F("Failed to read file, using default configuration"));

//     // 将 JSON 文档中的值复制到 Config 对象
//     config.port = doc["port"] | 2731;
//     strlcpy(config.hostname, doc["hostname"] | "example.com", sizeof(config.hostname));

//     // 关闭文件
//     file.close();
// }

// // 保存配置
// void saveConfiguration(const char *filename, const Config &config)
// {
//     // 删除现有文件，否则配置将附加到文件中
//     SPIFFS.remove(filename);

//     // 打开文件以供写入
//     File file = SPIFFS.open(filename, FILE_WRITE);
//     if (!file)
//     {
//         Serial.println(F("Failed to create file"));
//         return;
//     }

//     // 创建一个动态分配内存的 JsonDocument
//     DynamicJsonDocument doc(256);

//     // 在文档中设置值
//     doc["hostname"] = config.hostname;
//     doc["port"] = config.port;

//     // 将 JSON 序列化到文件
//     if (serializeJson(doc, file) == 0)
//     {
//         Serial.println(F("Failed to write to file"));
//     }

//     // 关闭文件
//     file.close();
// }

// // 打印文件内容到串行监视器
// void printFile(const char *filename)
// {
//     // 打开文件以供读取
//     File file = SPIFFS.open(filename, "r");
//     if (!file)
//     {
//         Serial.println(F("Failed to read file"));
//         return;
//     }

//     // 逐个字符提取文件内容并打印
//     while (file.available())
//     {
//         Serial.print((char)file.read());
//     }
//     Serial.println();

//     // 关闭文件
//     file.close();
// }

// void setup()
// {
//     // 初始化串行端口
//     Serial.begin(115200);
//     while (!Serial)
//         continue;

//     // 初始化 SPIFFS 文件系统
//     if (!SPIFFS.begin(true))
//     {
//         Serial.println(F("Failed to initialize SPIFFS"));
//         return;
//     }

//     // 在首次运行时加载默认配置
//     Serial.println(F("Loading configuration..."));
//     loadConfiguration(filename, config);

//     // 创建配置文件
//     Serial.println(F("Saving configuration..."));
//     saveConfiguration(filename, config);

//     // 打印配置文件内容
//     Serial.println(F("Print config file..."));
//     printFile(filename);
// }

// void loop()
// {
//     // 这个例子中不使用 loop 函数
// }
