#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

Adafruit_SH1106G display(128, 64, &Wire);

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  if (!display.begin(0x3C, true)) {
    Serial.println("OLED failed to start");
    while (1);
  }

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);

  display.println("OLED WORKING!");
  display.println("ESP32 OK");
ooo
  display.drawRect(0, 30, 128, 34, SH110X_WHITE);

  display.display();
}

void loop() {}


ESP32 + JMD 1.3A OLED (SH1106) Setup Guide
Overview

This project uses a 1.3-inch 128x64 OLED display (JMD 1.3A) with an ESP32 over I2C communication. The display is driven using the SH1106 controller.

Hardware Connections (I2C)
OLED Pin	ESP32 Pin
VCC	3.3V
GND	GND
SDA	GPIO 21
SCL	GPIO 22
Important Notes
Use 3.3V first (safe default for ESP32)
Keep wires short for stable display output
If screen is blank, verify I2C address (0x3C or 0x3D)
Required Arduino Libraries

Install these from Arduino Library Manager:

1. Adafruit GFX Library
Name: Adafruit GFX Library
Purpose: Core graphics functions (text, shapes, bitmap rendering)
2. Adafruit SH110X Library
Name: Adafruit SH110X
Purpose: Driver for SH1106 OLED controller used in JMD 1.3A
I2C Address

Most JMD 1.3A OLED modules use:

0x3C (most common)
0x3D (alternative)

If unsure, run an I2C scanner.

Basic Initialization Code
Wire.begin(21, 22);

if (!display.begin(0x3C, true)) {
  Serial.println("OLED failed");
  while (1);
}
Common Issues
Blank screen
Wrong I2C address
Missing GND connection
Wrong driver (must be SH1106, not SSD1306)
Not detected in scan
Wiring issue (SDA/SCL swapped)
No power to OLED
Compiles but nothing shows
Missing display.display();
Summary
Driver: SH1106 (Adafruit SH110X library)
Interface: I2C
ESP32 Pins: 21 (SDA), 22 (SCL)
Address: 0x3C / 0x3D

If you want, I can also 
turn this into a GitHub-ready project structure with examples and animations.