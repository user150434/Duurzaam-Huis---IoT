#include <ArduinoJson.h>

JsonDocument doc;
char jsonOut[128];

int lowest =  2000;
int highest = 0;
  void setup() {
  pinMode(A0,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  Hey();
}


void Hey(){
  
  int value = analogRead(A0);
  Serial.println(value);
  if(
  CreateJSON(value);

   digitalWrite(D3, LOW);
   digitalWrite(D5, LOW);
   digitalWrite(D6, LOW);
  if (value > 50 && value < 100)
  {
    digitalWrite(D3, HIGH);
  }
  if (value > 50 && value < 100)
  {
    digitalWrite(D5, HIGH);
  }
  if (value > 50 && value < 100)
  {
    digitalWrite(D6, HIGH);
  }
  
}

void CreateJSON(int value){
  doc["LOW"] = lowest;
  doc["HIGH"] = highest;
  serializeJson(doc,jsonOut);

  serializeJson(doc, Serial);
}
