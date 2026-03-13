# Temperature Monitoring and Thermal Control System

This project implements a **microcontroller-based temperature monitoring and control system** using Arduino.  
The system measures temperature using a sensor, displays the real-time value on a **16x2 LCD**, and automatically activates a **cooling fan** when the temperature exceeds a defined threshold.

The goal is to maintain the system temperature within the safe range **25°C – 50°C**.

---

## Project Overview

The system continuously reads temperature data from the sensor through the Arduino’s ADC.  
Based on the measured temperature, the controller determines the operating state and controls a cooling fan.

Three LEDs provide visual indication of the system status.

---

## System Features

- Real-time temperature monitoring  
- LCD temperature display  
- Automatic cooling fan control  
- LED status indicators  
- Overheat warning system  
- Simulation using **TinkerCAD**  
- Custom **PCB design using KiCad**

---

## Temperature Control Logic

| Temperature Range | Fan Status | LED Indicator | System State |
|------------------|------------|--------------|-------------|
| < 25°C | OFF | Green LED | Safe |
| 25°C – 50°C | ON | Yellow LED | Normal |
| > 50°C | ON | Red LED | Overheat |

---

## Hardware Components

- Arduino / ATmega328P
- Temperature sensor
- 16x2 LCD display
- DC cooling fan
- NPN transistor (fan driver)
- Flyback diode
- Status LEDs (Green, Yellow, Red)
- Resistors
- Potentiometer (LCD contrast)

---

## System Architecture

Temperature Sensor → Arduino ADC → Control Logic →  
LCD Display + Fan Driver + Status LEDs

---

## Simulation

The system was first validated using **TinkerCAD simulation** to verify:

- Temperature sensing
- LCD display output
- Automatic fan activation
- LED status indicators

Simulation results are available in the **images folder**.

---

## PCB Design

A custom PCB was designed using **KiCad**, including:

- Schematic design
- PCB layout
- ERC and DRC verification
- 3D PCB visualization

### PCB Layout
![PCB Layout](images/layout.png)

### 3D PCB View
![3D Top](images/3d_top.png)

---

## System Operation

Example outputs:

**Safe Condition**v
