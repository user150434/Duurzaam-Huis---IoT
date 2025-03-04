void setup() {
  // Set pin D3 on the NodeMCU as an
  // output pin so it can send voltages
  pinMode(D3, OUTPUT);
}

void loop() {
  // set a voltage on D3
  digitalWrite(D3, HIGH);
  // wait a second
  delay(1000);
  // remove voltage from D3
  digitalWrite(D3, LOW);
  // wait 2 seconds
  delay(200);


    for (int i = 0; i <= 255; i += 10) { // Verhoog helderheid
    analogWrite(D3, i);
    delay(50);
  }
  
  // LED dimmen
  for (int i = 255; i >= 0; i -= 20) { // Verlaag helderheid
    analogWrite(D3, i);
    delay(50);
  }



}
