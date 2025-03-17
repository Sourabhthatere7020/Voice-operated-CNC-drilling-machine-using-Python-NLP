# CNC Voice Operated CNC Drilling Machine using NLP in Python

## Project Overview
This project is a CNC Voice-Controlled Drill Machine designed as a final-year engineering project. The primary goal is to control a CNC drill machine using voice commands. The project utilizes an Arduino Uno with a CNC Shield V3 and A4988 stepper motor drivers, along with a voice recognition module implemented in Python. The spindle is controlled via a solid-state relay (FOTEK SSR-25 DA) and a JQC-3FF-S-Z low-level trigger relay.

## Features
- Voice-controlled movement along X, Y, and Z axes
- Spindle on/off control via voice commands
- Utilizes Python for voice recognition and Arduino for motor control
- End stops on the X-axis for safety and precision
- Smooth and precise control of stepper motors

## Hardware Components
1. Arduino Uno
2. CNC Shield V3 (HandsOn Technology)
3. A4988 Stepper Motor Drivers (3 units)
4. Stepper Motors (X, Y, Z axes)
5. FOTEK SSR-25 DA Solid State Relay
6. JQC-3FF-S-Z Low Level Trigger Relay
7. End Stop Switches (for X-axis)
8. 12-36V Power Supply
9. Spindle Motor

## Software Components
1. Arduino IDE
2. Python (for voice recognition)
3. PySerial Library (for serial communication)
4. SpeechRecognition Library (for voice commands)
5. AccelStepper Library (for stepper motor control)

## Wiring and Connections
### Stepper Motors
- X-axis motor connected to X pins on CNC Shield
- Y-axis motor connected to Y pins on CNC Shield
- Z-axis motor connected to Z pins on CNC Shield

### Spindle Control
- FOTEK SSR-25 DA connected to M0, M1, M2 pins on CNC Shield
- JQC-3FF-S-Z relay connected to SpnEn, GND, and 5V pins

### End Stops (X-axis)
- Connected to X+ and X- pins on CNC Shield

## Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/cnc-voice-drill
   ```
2. Install Python dependencies:
   ```bash
   pip install pyserial SpeechRecognition
   ```
3. Upload the C++ Arduino code to the Arduino Uno using the Arduino IDE. Run the C++ file in the arduino IDE envirnoment.
   ```bash
   VoiceCNC.cpp
   ```
## Usage
1. Power on the CNC machine.
2. Run the Python voice recognition script:
   ```bash
   VoiceCNC.py
   ```
3. Use voice commands to control the machine:
   - "Move left"
   - "Move right"
   - "Move up"
   - "Move down"
   - "Drill on"
   - "Drill off"

## Safety Precautions
- Always ensure proper grounding and insulation.
- Avoid contact with moving parts during operation.
- Use safety goggles and follow lab safety guidelines.

## Acknowledgements
Special thanks to the Open Source Community and the creators of libraries used in this project.

Feel Free to Give me a Feedback regarding this project on sourabhthatere6651@gmail.com
