#include <Keypad.h
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD (change to 0x3F if 0x27 does not work)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// KEYPAD CONFIG
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {14, 27, 26, 25};
byte colPins[COLS] = {33, 32, 13, 12};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// DATA STORAGE
String phone = "";
String amount = "";
bool enteringPhone = true;

// SHOW PHONE
void showPhone() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Phone:");
  lcd.setCursor(0,1);
  lcd.print(phone);
}

// SHOW AMOUNT
void showAmount() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Amount:");
  lcd.setCursor(0,1);
  lcd.print(amount);
}

// RESET SYSTEM
void resetAll() {
  phone = "";
  amount = "";
  enteringPhone = true;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter Phone:");
}

// FINAL SCREEN
void showFinal() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CONFIRMED");

  lcd.setCursor(0,1);
  lcd.print(phone);

  delay(2000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Amount:");
  lcd.setCursor(0,1);
  lcd.print(amount);
}

void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();

  resetAll();
}

void loop() {
  char key = keypad.getKey();

  if (key) {

    // RESET BUTTON (*)
    if (key == '*') {
      resetAll();
    }

    // NEXT STEP BUTTON (#)
    else if (key == '#') {
      if (enteringPhone) {
        enteringPhone = false;
        showAmount();
      } else {
        showFinal();
      }
    }

    // DIGIT INPUT
    else {
      if (enteringPhone) {
        phone += key;
        showPhone();
      } else {
        amount += key;
        showAmount();
      }
    }
  }
}




| LCD Pin | ESP32 Pin                |
| ------- | ------------------------ |
| VCC     | 5V (or 3.3V if required) |
| GND     | GND                      |
| SDA     | GPIO 21                  |
| SCL     | GPIO 22                  |


| Keypad Pin | ESP32 GPIO |
| ---------- | ---------- |
| R1         | 14         |
| R2         | 27         |
| R3         | 26         |
| R4         | 25         |
| C1         | 33         |
| C2         | 32         |
| C3         | 13         |
| C4         | 12         |
