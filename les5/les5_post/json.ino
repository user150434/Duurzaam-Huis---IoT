// JSON API: https://arduinojson.org/v6/api/

// JSON libraries
#include <ArduinoJson.h>

// JSON document
JsonDocument doc;


void CreateJSON() {
    doc["ldr"] = String(Light);
    doc["dht11"]["temperature"] = String(Temperature);
    doc["dht11"]["humidity"] = String(Humidity);
    doc["dht11"]["heatIndex"] = String(HeatIndex);

    serializeJson(doc, jsonOut);
}

void ReadJSON(String resJSON) {
    // remove "response: " from resJSON
    resJSON.remove(0, 9);

    StaticJsonDocument<200> resDoc;
    deserializeJson(resDoc, resJSON);

    digitalWrite(D3, bool(resDoc["lights"][0]));
    digitalWrite(D5, bool(resDoc["lights"][1]));
    digitalWrite(D6, bool(resDoc["lights"][2]));
}
