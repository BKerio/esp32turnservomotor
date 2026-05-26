#define TRIG_PIN 5
#define ECHO_PIN 18

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

float getDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000); 
  float distance = (duration * 0.0343) / 2;

  return distance;
}

void loop() {
  float distance = getDistanceCM();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}


| HC-SR04 Pin | ESP32 Pin |
| ----------- | --------- |
| VCC         | 5V        |
| GND         | GND       |
| TRIG        | GPIO 5    |
| ECHO        | GPIO 18   |
