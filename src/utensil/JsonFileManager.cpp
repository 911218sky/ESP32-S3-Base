#include <ArduinoJson.h>
#include "JsonFileManager.h"

_JsonFileManager::_JsonFileManager()
{
}


void _JsonFileManager::writeJson(const char *filename, DynamicJsonDocument &doc)
{
    // Open file for writing or create it if it doesn't exist
    File file = SPIFFS.open(filename, FILE_WRITE);

    if (!file)
    {
        Serial.println(F("Failed to open file"));
        return;
    }

    // If the file exists, try to read JSON data from the file
    DynamicJsonDocument existingDoc(1024); // Adjust the size to fit your data

    DeserializationError error = deserializeJson(existingDoc, file);
    if (error)
    {
        Serial.println(F("Failed to read existing file, using new data"));
        existingDoc.clear();
    }

    // Close the file to reset the file pointer before reading again
    file.close();

    // Reopen the file to read the JSON data again
    file = SPIFFS.open(filename, FILE_READ);

    // Merge new data into existing data, preserving contents of the original file that aren't changed
    JsonObject obj = doc.as<JsonObject>();
    for (JsonObject::iterator it = obj.begin(); it != obj.end(); ++it)
    {
        existingDoc[it->key()] = it->value();
    }

    // Close the file before writing
    file.close();

    // Reopen the file to write the JSON data
    file = SPIFFS.open(filename, FILE_WRITE);

    // Serialize JSON to file
    if (serializeJson(existingDoc, file) == 0)
    {
        Serial.println(F("Failed to write to file"));
    }

    // Close the file
    file.close();
}

bool _JsonFileManager::readJson(const char *filename, DynamicJsonDocument &doc)
{
    // Open the file for reading
    File file = SPIFFS.open(filename, "r");

    if (!file) {
        Serial.println(F("Failed to open file for reading"));
        return false;
    }

    // Create a local DynamicJsonDocument, do not shadow the function parameter
    DynamicJsonDocument localDoc(512);

    // Deserialize data from the JSON document
    DeserializationError error = deserializeJson(localDoc, file);
    if (error) {
        Serial.println(F("Failed to read file, using default configuration"));
        file.close();
        return false;
    }

    // Assign the read data to the passed in document
    doc = localDoc;

    // Close the file
    file.close();
    return true; // Don't forget to return true if the operation was successful
}


void _JsonFileManager::printFile(const char *filename) {
    // Open file for reading
    File file = SPIFFS.open(filename, FILE_READ);

    // Check if the file is available
    if (!file) {
        Serial.println(F("Failed to open file for reading"));
        return;
    }

    Serial.println(F("File Content:"));

    // Read file and print to the Serial
    while (file.available()) {
        // You can read and print line by line
        String line = file.readStringUntil('\n');
        Serial.println(line);
    }

    // Close the file
    file.close();
}

_JsonFileManager JsonFileManager;