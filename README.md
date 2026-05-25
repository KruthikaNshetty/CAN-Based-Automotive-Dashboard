# CAN-Based-Automotive-Dashboard

## Description

The CAN Based Automotive Dashboard is an embedded system project developed using Embedded C and CAN (Controller Area Network) protocol.

This project simulates a real-time automotive communication system where multiple ECUs communicate through the CAN bus to exchange vehicle information such as:
- Vehicle Speed
- Gear Position
- Engine RPM
- Indicator Status

The received data is displayed on a CLCD dashboard in real time.

The project demonstrates how modern automotive systems use distributed ECUs and CAN communication for reliable and efficient data exchange.

## 🚗 Features

- Real-time speed monitoring
- Gear position monitoring
- RPM monitoring
- Left, Right, Hazard indicator control
- CAN bus communication
- Multi-ECU communication
- CLCD dashboard display
- ADC based sensor reading
- Digital keypad input handling
- Interrupt based processing
- Timer based operations

## 🛠 Technologies Used

- Embedded C
- PIC Microcontroller
- MPLAB X IDE
- XC8 Compiler
- CAN Protocol
- ADC
- CLCD Display
- Digital Keypad
- Timer
- Interrupts


## ⚙️ System Working

### ECU1
- Reads vehicle speed using ADC
- Detects gear position using keypad
- Sends speed and gear data through CAN bus

### ECU2
- Reads engine RPM using ADC
- Processes indicator controls
- Sends RPM and indicator status through CAN bus

### Dashboard ECU
- Receives CAN messages
- Processes CAN bus data
- Displays vehicle information on CLCD


