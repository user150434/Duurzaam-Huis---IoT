const int ledD3 = 3;
const int ledD5 = 5;
const int ledD6 = 6;

void setup() {
  Serial.begin(9600);
  pinMode(ledD3, OUTPUT);
  pinMode(ledD5, OUTPUT);
  pinMode(ledD6, OUTPUT);
}

void loop() {
  int A = random(999), B = random(999), C = random(999), D = random(999);

  Serial.print("A: "); Serial.println(A);
  Serial.print("B: "); Serial.println(B);
  Serial.print("C: "); Serial.println(C);
  Serial.print("D: "); Serial.println(D);

  digitalWrite(ledD3, (A > B || A < C));
  digitalWrite(ledD5, (C > A && A < B));
  digitalWrite(ledD6, (B > C && B > A && C < A));

  if (D >= max(max(A, B), C)) {
    for (int i = 0; i < 10; i++) {
      digitalWrite(ledD3, HIGH);
      digitalWrite(ledD5, HIGH);
      digitalWrite(ledD6, HIGH);
      delay(100);
      digitalWrite(ledD3, LOW);
      digitalWrite(ledD5, LOW);
      digitalWrite(ledD6, LOW);
      delay(100);
    }
  }

  delay(10000);
}
