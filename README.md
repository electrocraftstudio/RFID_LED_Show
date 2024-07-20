# RFID LED Show with Sound Effects

## Overview

This project uses an RFID-RC522 module to control an LED light show with sound effects. When a specific RFID card is detected, different patterns of LED lights will be displayed, and a buzzer will play a sound.

## Required Components

- Arduino Uno
- RFID-RC522 module
- 5 LEDs
- 5 x 220Ω resistors
- Buzzer
- Breadboard and jumper wires
- USB cable to connect Arduino to the computer

## Libraries to Install

1. **MFRC522 Library**
   - Open the Arduino IDE.
   - Go to **Sketch** > **Include Library** > **Manage Libraries**.
   - In the Library Manager, search for "MFRC522".
   - Install the library by Miguel Balboa.

## Wiring Connections

**RFID-RC522 Module:**
- **SDA** -> D10
- **SCK** -> D13
- **MOSI** -> D11
- **MISO** -> D12
- **RST** -> D9
- **GND** -> GND
- **3.3V** -> 3.3V

**LED Connections:**
- **LED1:** Anode -> 220Ω resistor -> D2, Cathode -> GND
- **LED2:** Anode -> 220Ω resistor -> D3, Cathode -> GND
- **LED3:** Anode -> 220Ω resistor -> D4, Cathode -> GND
- **LED4:** Anode -> 220Ω resistor -> D5, Cathode -> GND
- **LED5:** Anode -> 220Ω resistor -> D6, Cathode -> GND

**Buzzer Connection:**
- **Positive Leg** -> D7
- **Negative Leg** -> GND

## Steps to Upload the Code

1. **Open the Arduino IDE.**
2. **Install the Required Library:**
   - Go to **Sketch** > **Include Library** > **Manage Libraries**.
   - Search for and install the "MFRC522" library.
3. **Connect the Arduino to the Computer:**
   - Use the USB cable to connect your Arduino Uno to your computer.
4. **Upload the Code:**
   - Open the provided `.ino` file in the Arduino IDE.
   - Select the correct board and port under **Tools**.
   - Click the **Upload** button.

## Project Setup

1. **Connect the RFID-RC522 module to the Arduino:**
   - Connect SDA to D10, SCK to D13, MOSI to D11, MISO to D12, RST to D9, GND to GND, and 3.3V to 3.3V.
2. **Connect the LEDs to the Arduino:**
   - Connect the anode of each LED to a 220Ω resistor, then connect the resistor to D2, D3, D4, D5, and D6 respectively. Connect the cathode of each LED to GND.
3. **Connect the Buzzer to the Arduino:**
   - Connect the positive leg to D7 and the negative leg to GND.
4. **Upload the code from the Arduino IDE.**

## Testing the Project

1. **Power the Arduino:**
   - Once the code is uploaded, keep the Arduino connected to your computer or power it using an external power source.
2. **Test the RFID Functionality:**
   - Present the RFID cards to the RFID-RC522 module.
   - Observe the LED patterns and listen for the buzzer sound.

## Troubleshooting

- **Check Connections:**
  - Ensure all connections are secure and correctly placed according to the wiring diagram.
- **Library Issues:**
  - Make sure the MFRC522 library is correctly installed.
- **Serial Monitor:**
  - Use the Serial Monitor (Tools > Serial Monitor) to view debug messages and ensure the RFID cards are being read correctly.
