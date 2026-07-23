
>**Critical:** The external power supply ground **must** be connected to ESP32 GND. Do not power the servo from the ESP32 3.3V or 5V pins.rr

---

## Dependencies

Install via **Arduino IDE Library Manager** (`Sketch → Include Library → Manage Libraries`):

| Library | Version | Search Term |
|---------|---------|-------------|
| ESP32Servo | Latest | `ESP32Servo` by Kevin Harrington |

### Board Setup

1. **File → Preferences → Additional Board Manager URLs**
2. Add: `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
3. **Tools → Board → Boards Manager**
4. Search **"ESP32"** → Install **"ESP32 by Espressif Systems"**
5. **Tools → Board → ESP32 Arduino → ESP32 Dev Module**

---

## Installation & Upload

1. **Clone this repository**
   ```bash
   git clone https://github.com/yourusername/esp32-servo-controller.git
   cd esp32-servo-controller


   Open esp32_servo.ino in Arduino IDE
Select board settings:  
Board: ESP32 Dev Module
Port: Your COM port (e.g., COM4, COM5)
Upload Speed: 92160
Upload the sketch
If upload fails, hold the BOOT button → click Upload → release BOOT when "Connecting...." appears.
