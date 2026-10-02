# Multi-Zone Temperature Monitoring System

An Arduino project that monitors temperature in multiple zones using DHT11
sensors. The highest temperature across all zones determines the system
status, which is displayed through LEDs and the Serial Monitor.

## Features
- Monitors 2 temperature zones simultaneously
- Each zone's data is stored in a `struct` (pin, temperature, zone name)
- Automatic status based on the highest temperature
- Output to Serial Monitor (9600 baud)

## Temperature Status
| Highest temperature | Status  | LED (pin) |
|---------------------|---------|-----------|
| > 40 °C             | DANGER  | 13        |
| 30 - 40 °C          | WARNING | 12        |
| < 30 °C             | NORMAL  | 11        |

## Components
- Arduino Uno
- 2x DHT11 sensors (pins A5 and A4)
- 3x LEDs + 220 Ω resistors
- Jumper wires and breadboard

## Library
- [DHT sensor library](https://github.com/adafruit/DHT-sensor-library) by Adafruit

## Usage
1. Wire the components according to the pin table above.
2. Install the DHT library through the Arduino IDE Library Manager.
3. Upload the code to the Arduino.
4. Open the Serial Monitor (9600 baud) to see the temperatures and status.

## Notes
The DHT11 needs at least about 1 second between readings.

<img width="1080" height="686" alt="image" src="https://github.com/user-attachments/assets/496be297-1843-48c5-b11c-2166a2315201" />

## Simulation Note (Wokwi)

Wokwi does not have a DHT11 component, so the circuit in the simulation uses
a **DHT22** instead. Both sensors work the same way in code: the same library,
the same `readTemperature()` function, and the same wiring. The only
difference is one line:

```
#define DHTTYPE DHT11   // real hardware with DHT11
#define DHTTYPE DHT22   // Wokwi simulation (or real DHT22)
```

The DHT22 is also more accurate (±0.5 °C with decimal readings), so the
temperature thresholds work without any other changes.
