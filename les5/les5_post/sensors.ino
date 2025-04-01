#include "DHT.h"
#define DHTTYPE DHT11
uint8_t DHTPin = D7;
DHT dht(DHTPin, DHTTYPE);


 void ReadDHT11() {
  float temperature = round(dht.readTemperature()*10)/10;
  float humidity = round(dht.readHumidity()*10)/10;
  float heatIndex = round(dht.computeHeatIndex(temperature, humidity, false)*10)/10;
  int ldrValue = analogRead(LDR_Pin);
  if(isnan(temperature) || isnan(humidity) || isnan(heatIndex))
    {
      Serial.println("DHT11 sensor error");
    }
   else{
    Temperature = temperature;
    Humidity = humidity;
    HeatIndex = heatIndex;

    Serial.println("Temp: " + String(Temperature) + ".C");
    Serial.println("Humidity: " + String(Humidity));
    Serial.println("% HeatIndex: " + String(HeatIndex) + "\n");
   }
}
