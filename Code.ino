#include <SPI.h>
#include <SD.h>

const int chipSelect = 10; // CS Pin
String input = "";

void setup() {
  Serial.begin(9600);

  if (!SD.begin(chipSelect)) {
    Serial.println("SD Card initialization failed!");
    return;
  }
  Serial.println("SD Card initialized.");
}

void loop() {
  Serial.println("Enter RFID Code:");
  
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      input.trim();
      if (input.length() > 0) {
        if (isRegistered(input)) {
          Serial.println("Already Registered");
        } else {
          registerRFID(input);
          Serial.println("RFID Registered");
        }
      }
      input = ""; // Clear input buffer
    } else {
      input += c;
    }
  }
}

bool isRegistered(String code) {
  File file = SD.open("rfid.txt");
  if (file) {
    while (file.available()) {
      String line = file.readStringUntil('\n');
      line.trim();
      if (line == code) {
        file.close();
        return true;
      }
    }
    file.close();
  }
  return false;
}

void registerRFID(String code) {
  File file = SD.open("rfid.txt", FILE_WRITE);
  if (file) {
    file.println(code);
    file.close();
  }
}
