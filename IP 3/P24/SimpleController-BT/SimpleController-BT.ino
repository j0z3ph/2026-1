/*
  SimpleController-BT.ino
  SimpleController Bluetooth Compatible Sketch v0.1 (2025-5-6)
  Copyright (c) 2025 Jose Luis Cruz Mora

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#ifdef ESP32
#include <ESP32Servo.h>
#include "BluetoothSerial.h"
#else
#include <Servo.h>
#endif

#define BAUD 115200
// Message command bytes (0x80(128) to 0xFF(255))
#define DIGITAL_READ 0x80
#define DIGITAL_WRITE 0x81
#define ANALOG_READ 0x82
#define ANALOG_WRITE 0x83
#define SERVO_WRITE 0x84
#define SERVO_CONFIG 0x85
#define SET_PIN_MODE 0x86  // (input, output, etc.)

#define RESET_MESSAGE 0xFF  // Reset board message
#define DEVICE_INFO 0xF0    // Get device type ID

#define MODE_INPUT 0
#define MODE_OUTPUT 1
#define MODE_SERVO 2         // digital pin in SERVO mode
#define MODE_INPUT_PULLUP 3  // Same as INPUT, but with the pin's internal pull-up resistor enabled
#ifdef ESP32
#define DEVICE 1  // ESP32
#else
#define DEVICE 0  // ARDUINO
#endif

// Globals

// format: command, pin, dataH, dataL
byte _inbuffer[4];
byte _outbuffer[4];

size_t _bytesRead;
uint16_t _analogDataRead;

Servo _servo;

#ifdef ESP32
String device_name = "IP 1MM3 ESP32";
BluetoothSerial SerialBT;
#endif

// Only for Arduino reset
void (*softReset)(void) = 0;
// Process input message
void processInput(byte argc, byte *argv);

void setup() {
#ifdef ESP32
  SerialBT.begin(device_name);
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
#else
  Serial.begin(BAUD);
#endif
}

void loop() {
  #ifdef ESP32
  if (SerialBT.available()) {
    _bytesRead = SerialBT.readBytes(_inbuffer, 4); // Read 4 bytes
    if (_bytesRead) {
      processInput(_bytesRead, _inbuffer);
    }
  }
  #else
  if (Serial.available()) {
    _bytesRead = Serial.readBytes(_inbuffer, 4); // Read 4 bytes
    if (_bytesRead) {
      processInput(_bytesRead, _inbuffer);
    }
  }
  #endif
}

void processInput(byte argc, byte *argv) {
  if (argc) {

    switch (argv[0]) {
      case DEVICE_INFO:
        // input format: command, don't care, don't care, don't care
        // output format: command, value
        if (argc > 1) {
          _outbuffer[0] = argv[0];  // command
          _outbuffer[1] = DEVICE;   // Dev ID
          #ifdef ESP32
          SerialBT.write(_outbuffer, 2);
          #else
          Serial.write(_outbuffer, 2);
          #endif
        }
        break;
      case RESET_MESSAGE:
#ifdef ESP32
        esp_restart();
#else
        softReset();
#endif
        break;
      case SET_PIN_MODE:
        // input format: command, pin, 0, mode
        if (argc > 3) {
          switch (argv[3]) {
            case MODE_INPUT:
              pinMode(argv[1], INPUT);
              break;
            case MODE_OUTPUT:
              pinMode(argv[1], OUTPUT);
              digitalWrite(argv[1], LOW);
              break;
            case MODE_INPUT_PULLUP:
              pinMode(argv[1], INPUT_PULLUP);
              break;
            case MODE_SERVO:
              _servo.attach(argv[1]);
              break;
            default:
              break;
          }
        }
        break;
      case DIGITAL_READ:
        // input format: command, pin, don't care, don't care
        // output format: command, pin, 0, value
        if (argc > 1) {
          _outbuffer[0] = argv[0];               // command
          _outbuffer[1] = argv[1];               // pin
          _outbuffer[2] = 0;                     // 0
          _outbuffer[3] = digitalRead(argv[1]);  // value
          #ifdef ESP32
          SerialBT.write(_outbuffer, 4);
          #else
          Serial.write(_outbuffer, 4);
          #endif
        }
        break;
      case DIGITAL_WRITE:
        // input format: command, pin, 0, value
        if (argc > 3) {
          digitalWrite(argv[1], (argv[3] ? HIGH : LOW));
        }
        break;
      case ANALOG_READ:
        // input format: command, pin, don't care, don't care
        // output format: command, pin, msb, lsb
        if (argc > 1) {
          _outbuffer[0] = argv[0];  // command
          _outbuffer[1] = argv[1];  // pin
          _analogDataRead = analogRead(argv[1]);
          _outbuffer[2] = (_analogDataRead >> 8);      // msb
          _outbuffer[3] = (_analogDataRead & 0x00FF);  // lsb
          #ifdef ESP32
          SerialBT.write(_outbuffer, 4);
          #else
          Serial.write(_outbuffer, 4);
          #endif
        }
        break;
      case ANALOG_WRITE:
        // input format: command, pin, msb, lsb
        if (argc > 3) {
          analogWrite(argv[1], ((argv[2] << 8) | argv[3]));
        }
        break;
      case SERVO_CONFIG:
        // input format: command, pin, 0, 0
        if (argc > 1) {
#ifdef ESP32
          _servo.setPeriodHertz(50);  // Standard 50hz servo
          _servo.attach(argv[1], 50, 2400);
#else
          _servo.attach(argv[1]);
#endif
        }
        break;
      case SERVO_WRITE:
        // input format: command, pin, 0, angle
        if (argc > 3) {
          _servo.write(argv[3]);
        }
        break;
      default:
        break;
    }
  }
}
