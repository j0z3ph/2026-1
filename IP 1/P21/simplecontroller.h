/**
  SimpleController client for communication to Arduino/ESP32 board
  loaded with SimpleController sketch.
  
  SimpleController C client v0.1 (2025-2-5)
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
**/

#ifndef __SIMPLECONTROLLER_H__
#define __SIMPLECONTROLLER_H__

#include <stdbool.h>
#include "serial.h"

/// Constants

#define DIGITAL_READ 0x80
#define DIGITAL_WRITE 0x81
#define ANALOG_READ 0x82
#define ANALOG_WRITE 0x83
#define SERVO_WRITE 0x84
#define SERVO_CONFIG 0x85
#define SET_PIN_MODE 0x86
#define RESET_MESSAGE 0xFF
#define DEVICE_INFO 0xF0

/// Device modes

#define INPUT 0
#define OUTPUT 1
#define SERVO 2
#define INPUT_PULLUP 3

/// Device IDs

#define ARDUINO 0
#define ESP32 1

/// Types

#ifdef _WIN32
typedef unsigned char uint8_t;
typedef unsigned int uint;
#endif

/// @brief Base structure
typedef struct Board
{
    uint8_t _device;
    SerialPort sp;
    uint8_t command[4];
    uint8_t byte;
    /// @brief Sets mode to a pin
    /// @param self Board pointer
    /// @param pin Desired pin number
    /// @param mode Desired mode. See for allowed modes constants.
    void (*pinMode)(struct Board *self, uint8_t pin, uint8_t mode);
    /// @brief Sends value to digital port
    /// @param self Board pointer
    /// @param pin Desired pin number
    /// @param value Value
    void (*digitalWrite)(struct Board *self, uint8_t pin, bool value);
    /// @brief Sends value to analog port
    /// @param self Board pointer
    /// @param pin Desired pin number
    /// @param value Float value between 0 and 1
    void (*analogWrite)(struct Board *self, uint8_t pin, float value);
    /// @brief Reads a digital port
    /// @param self Board pointer
    /// @param pin Desired pin number
    /// @return Value
    bool (*digitalRead)(struct Board *self, uint8_t pin);
    /// @brief Reads an analog port
    /// @param self Board pointer
    /// @param pin Desired pin number
    /// @return Normalized readed value. Floatting point number between 0 and 1.
    float (*analogRead)(struct Board *self, uint8_t pin);
    /// @brief Configure one pin as a servo motor
    /// @param self Board pointer
    /// @param pin Desired pin number
    void (*attachServo)(struct Board *self, uint8_t pin);
    /// @brief Sends angle to servo motor
    /// @param self Board pointer
    /// @param angle Desired angle from 0 to 180 degrees.
    void (*servoWrite)(struct Board *self, uint8_t angle);
    /// @brief Close serial communication and release board pointer
    /// @param self Board pointer
    void (*closeDevice)(struct Board *self);

} Board;

/// @brief Creates a new object that represents an Arduino or ESP32
/// @param portName Port where the device is connected
/// @param baudrate Baud rate (115200 by default)
/// @return Board object or NULL if cannot initialize the communication
Board *connectDevice(const char *portName, BaudRate baudrate);

/// @brief Sets mode to a pin
/// @param self Board pointer
/// @param pin Desired pin number
/// @param mode Desired mode. See for allowed modes constants.
void pinMode(Board *self, uint8_t pin, uint8_t mode);
/// @brief Sends value to digital port
/// @param self Board pointer
/// @param pin Desired pin number
/// @param value Value
void digitalWrite(Board *self, uint8_t pin, bool value);
/// @brief Sends value to analog port
/// @param self Board pointer
/// @param pin Desired pin number
/// @param value Float value between 0 and 1
void analogWrite(Board *self, uint8_t pin, float value);
/// @brief Reads a digital port
/// @param self Board pointer
/// @param pin Desired pin number
/// @return Value
bool digitalRead(Board *self, uint8_t pin);
/// @brief Reads an analog port
/// @param self Board pointer
/// @param pin Desired pin number
/// @return Normalized readed value. Floatting point number between 0 and 1.
float analogRead(Board *self, uint8_t pin);
/// @brief Configure one pin as a servo motor
/// @param self Board pointer
/// @param pin Desired pin number
void attachServo(Board *self, uint8_t pin);
/// @brief Sends angle to servo motor
/// @param self Board pointer
/// @param angle Desired angle from 0 to 180 degrees.
void servoWrite(Board *self, uint8_t angle);
/// @brief Close serial communication and release board pointer
/// @param self Board pointer
void closeDevice(Board *self);

#endif