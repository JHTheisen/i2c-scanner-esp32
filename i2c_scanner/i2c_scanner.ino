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
      Serial.print("Device found at 0x");
      Serial.println(address, HEX);
      deviceFound = true;
      break; // stop at first device
    }
  }

  if (deviceFound) {
    digitalWrite(LED_FOUND, HIGH);
    digitalWrite(LED_NOT_FOUND, LOW);
  } else {
    digitalWrite(LED_FOUND, LOW);
    digitalWrite(LED_NOT_FOUND, HIGH);
  }

  delay(1000);
}
