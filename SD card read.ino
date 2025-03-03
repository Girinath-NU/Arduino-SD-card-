#include <SPI.h>
#include <SD.h>

const int chipSelect = 4;  // SD Card CS Pin

void setup() {
  Serial.begin(9600);
  
  if (!SD.begin(chipSelect)) {
    Serial.println("SD Card Initialization Failed!");
    return;
  }
  Serial.println("SD Card Initialized!");

  readRFIDValues();  // Function to read stored values
}

void loop() {
  // Nothing in loop
}

void readRFIDValues() {
  File file = SD.open("rfid.txt");  // Open file to read
  if (file) {
    Serial.println("Stored RFID Values:");

    while (file.available()) {
      String line = file.readStringUntil('\n');  // Read line by line
      line.trim();  // Remove unwanted spaces
      if (line.length() > 0) {
        Serial.println(line);  // Print UID
      }
    }

    file.close();  // Close file
  } else {
    Serial.println("Error opening file!");
  }
}
