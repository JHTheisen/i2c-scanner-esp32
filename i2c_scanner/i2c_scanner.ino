#include <Wire.h>

#define SDA_PIN 21
#define SCL_PIN 22

#define LED_FOUND 2     // lights when device found
#define LED_NOT_FOUND 4 // lights when no device

void setup() {
  Serial.begin(115200);

  pinMode(LED_FOUND, OUTPUT);
  pinMode(LED_NOT_FOUND, OUTPUT);

  digitalWrite(LED_FOUND, LOW);
  digitalWrite(LED_NOT_FOUND, LOW);

  Wire.begin(SDA_PIN, SCL_PIN);

  delay(1000); // let things settle
}

void loop() {
  bool deviceFound = false;

  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at 0x");

      if (address < 16) {
        Serial.print("0");
      }

      Serial.println(address, HEX);
      deviceFound = true;
    }
  }

  if (deviceFound) {
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
  } else {
    Serial.println("No I2C devices found");
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
  }

  delay(5000);
}
