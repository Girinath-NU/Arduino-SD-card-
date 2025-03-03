# RFID Registration System with SD Card

## Description
This project is an **RFID Registration System** using an **Arduino**, **SD card module**, and **Serial Monitor**. The system allows users to input RFID codes via the serial monitor, store them in an SD card, and check for duplicate entries.

## Features
- Store RFID codes in an SD card
- Detect duplicate RFID codes
- Real-time registration via Serial Monitor
- Persistent storage using SD card

## Components Required
- Arduino Board (Uno/Nano)
- SD Card Module
- SD Card (formatted as FAT32)
- Jumper Wires
- 3.3V Power Supply

## Pin Connections
| SD Module Pin | Arduino Pin |
|---------------|-------------|
| 3V3          | 3.3V        |
| GND          | GND        |
| CS           | D10        |
| MOSI         | D11        |
| CLK (SCK)    | D13        |
| MISO         | D12        |

## Library Used
- `SPI.h`
- `SD.h`

## Code Explanation
1. **SD Card Initialization**: Checks if the SD card is properly initialized.
2. **User Input**: Accepts RFID codes via the serial monitor.
3. **Duplicate Check**: Searches for existing codes in `rfid.txt`.
4. **Registration**: Writes new codes to the SD card if not already registered.
5. **Confirmation Messages**: Displays appropriate messages on the Serial Monitor.

## How to Use
1. Upload the code to the Arduino.
2. Open the **Serial Monitor**.
3. Type the RFID code and press **Enter**.
4. The system will display:
   - "RFID Registered" if the code is new.
   - "Already Registered" if the code exists.

## File Structure on SD Card
```
rfid.txt
  - 12345
  - 67890
  - ABC123
```

## Troubleshooting
- Make sure the SD card is formatted as **FAT32**.
- Use SD cards of size **≤ 32GB**.
- Check wiring connections.
- Ensure the CS pin matches the code.

## License
This project is open-source and available under the MIT License.
