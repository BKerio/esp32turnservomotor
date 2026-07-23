#include <ESP32Servo.h>

Servo myServo;

// Safe GPIO pins for ESP32 servo: 13, 14, 16, 17, 18, 19, 21, 22, 23, 25, 26, 27, 32, 33
// Avoid: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 15 (used for boot/flash/UART)
int servoPin = 13;uuug

void setup() {
  // Allow allocation of all timers for servo
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  
  myServo.setPeriodHertz(50);           // Standard 50Hz servo
  myServo.attach(servoPin, 500, 2400);  // Min/max pulse width in microseconds
  
  Serial.begin(115200);
  Serial.println("Servo ready on GPIO 13!");
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos);
    delay(15);
  }
  
  for (int pos = 180; pos >= 0; pos -= 1) {
    myServo.write(pos);
    delay(15);
  }
}