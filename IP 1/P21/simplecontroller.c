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

#include <stdio.h>
#include "simplecontroller.h"
#include "serial.h"

Board *connectDevice(const char *portName, BaudRate baudrate)
{
    Board *b = (Board *)malloc(sizeof(Board));
    b->pinMode = pinMode;
    b->digitalWrite = digitalWrite;
    b->analogWrite = analogWrite;
    b->digitalRead = digitalRead;
    b->analogRead = analogRead;
    b->attachServo = attachServo;
    b->servoWrite = servoWrite;
    b->closeDevice = closeDevice;

    b->sp = initSerialPort(portName, baudrate);

    if (!isConnected(&b->sp))
    {
        printf("\nCould not connect to the device.\n");
        free(b);
        return NULL;
    }

    //memset(b->command, 0, 4);
    //b->command[0] = RESET_MESSAGE;
    //writeSerialPort(b->command, 4, &b->sp);
    Sleep(2000);
    b->command[0] = DEVICE_INFO;
    writeSerialPort(b->command, 4, &b->sp);
    Sleep(10);
    readSerialPort(&b->byte, 1, &b->sp);
    if (!b->byte)
    {
        printf("Could not get any response from the device.\n");
        printf("Make sure you have uploaded SimpleController sktech to your Arduino/ESP32.\n");
        closeSerial(&b->sp);
        free(b);
        return NULL;
    }
    while (b->byte != DEVICE_INFO)
    {
        readSerialPort(&b->byte, 1, &b->sp);
        if (!b->byte)
        {
            printf("Could not get any response from the device.\n");
            printf("Make sure you have uploaded SimpleController sktech to your Arduino/ESP32.\n");
            closeSerial(&b->sp);
            free(b);
            return NULL;
        }
    }
    readSerialPort(&b->byte, 1, &b->sp);
    b->_device = b->byte;
    return b;
}

void pinMode(Board *self, uint8_t pin, uint8_t mode)
{
    self->command[0] = SET_PIN_MODE;
    self->command[1] = pin;
    self->command[2] = 0;
    self->command[3] = mode;
    writeSerialPort(self->command, 4, &self->sp);
}

void digitalWrite(Board *self, uint8_t pin, bool value)
{
    self->command[0] = DIGITAL_WRITE;
    self->command[1] = pin;
    self->command[2] = 0;
    self->command[3] = value;
    writeSerialPort(self->command, 4, &self->sp);
}

void analogWrite(Board *self, uint8_t pin, float value)
{
    float val = (value < 0.0f ? 0.0f : (value > 1.0f ? 1.0f : value));
    self->byte = (uint8_t)(val * 255);
    self->command[0] = ANALOG_WRITE;
    self->command[1] = pin;
    self->command[2] = 0;
    self->command[3] = self->byte;
    writeSerialPort(self->command, 4, &self->sp);
}

bool digitalRead(Board *self, uint8_t pin)
{

    self->command[0] = DIGITAL_READ;
    self->command[1] = pin;
    self->command[2] = 0;
    self->command[3] = 0;
    writeSerialPort(self->command, 4, &self->sp);
    readSerialPort(&self->byte, 1, &self->sp);
    if (!self->byte)
    {
        return false;
    }
    if (self->byte == DIGITAL_READ)
    {
        readSerialPort(&self->byte, 1, &self->sp);
        if (self->byte == pin)
        {
            uint val;
            readSerialPort(&self->byte, 1, &self->sp);
            val = (uint)(self->byte) << 8;
            readSerialPort(&self->byte, 1, &self->sp);
            val += (uint)self->byte;
            return val;
        }
    }
    return false;
}

float analogRead(Board *self, uint8_t pin)
{
    self->command[0] = ANALOG_READ;
    self->command[1] = pin;
    self->command[2] = 0;
    self->command[3] = 0;
    writeSerialPort(self->command, 4, &self->sp);
    readSerialPort(&self->byte, 1, &self->sp);
    if (!self->byte)
    {
        return 0.0f;
    }
    if (self->byte == ANALOG_READ)
    {
        readSerialPort(&self->byte, 1, &self->sp);
        if (self->byte == pin)
        {
            uint val;
            float fval;
            readSerialPort(&self->byte, 1, &self->sp);
            val = (uint)(self->byte) << 8;
            readSerialPort(&self->byte, 1, &self->sp);
            val += (uint)self->byte;

            if (self->_device == ARDUINO)
                fval = (float)val / 1023.0f;
            else
                fval = (float)val / 4095.0f;
            return fval;
        }
    }
    return 0.0f;
}

void attachServo(Board *self, uint8_t pin)
{
    self->command[0] = SERVO_CONFIG;
    self->command[1] = pin;
    self->command[2] = 0;
    self->command[3] = 0;
    writeSerialPort(self->command, 4, &self->sp);
}

void servoWrite(Board *self, uint8_t angle)
{
    uint8_t ang = (angle > 180 ? 180 : angle);
    self->command[0] = SERVO_WRITE;
    self->command[1] = 0;
    self->command[2] = 0;
    self->command[3] = ang;
    writeSerialPort(self->command, 4, &self->sp);
}

void closeDevice(Board *self)
{
    closeSerial(&self->sp);
    free(self);
}