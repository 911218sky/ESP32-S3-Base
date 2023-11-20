#ifndef _JSON_FILE_MANAGER_H_
#define _JSON_FILE_MANAGER_H_

#include <ArduinoJson.h>

#ifndef _SPIFFS_H_
#include <SPIFFS.h>
#endif

#define JSON_FILE_SIZE 1024

class _JsonFileManager
{
public:
    _JsonFileManager();

    void writeJson(const char *filename, DynamicJsonDocument &doc);
    bool readJson(const char *filename, DynamicJsonDocument &jsdocon);
    void printFile(const char *filename);
};

extern _JsonFileManager JsonFileManager;

#endif
