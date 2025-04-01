#define MAX_UNSIGNED_LONG 4294967295
#define DHT11ReadDelay 5000

// GLOBAL VARIABLES
// json
char jsonOut[128];
// dht11
float Temperature = -1;
float Humidity = -1;
float HeatIndex = -1;
// light sensor
int Light = -1;


void setup() {
  Serial.begin(115200);
  
  SetupWifi();
  CheckWifi();
}

void loop() {
  static unsigned long previousTime = 0;
  unsigned long currentTime = millis();

  // this is separated so the LDR can work constinously
  if(currentTime - previousTime >= DHT11ReadDelay || currentTime >= MAX_UNSIGNED_LONG - DHT11ReadDelay) {
    // Clear monitor
    Serial.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    Serial.println("Reading sensors\n");
    
        loopSensors();

        Serial.println("Creating JSON\n");

        CreateJSON();
        SendJSONToSerial();

        Serial.println("Sending POST\n");
        SendPOST(jsonOut);

        previousTime = currentTime;
  }

  CheckWifi();
  delay(50);
}
