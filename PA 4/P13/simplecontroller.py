"""SimpleController client for communication to Arduino/ESP32 board
loaded with SimpleController sketch.
"""

"""
  SimpleController python client v0.1 (2025-2-4)
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
"""

import serial
import time

# Constants
DIGITAL_READ = 0x80
DIGITAL_WRITE = 0x81
ANALOG_READ = 0x82
ANALOG_WRITE = 0x83
SERVO_WRITE = 0x84
SERVO_CONFIG = 0x85
SET_PIN_MODE = 0x86
RESET_MESSAGE = 0xFF
DEVICE_INFO = 0xF0

# Modes
INPUT = 0
OUTPUT = 1
SERVO = 2
INPUT_PULLUP = 3

# Devices
ARDUINO = 0
ESP32 = 1


class Board:
    """Main class for Arduino and ESP32"""

    def __init__(self, port: str, baudrate: int = 115200):
        """Constructor

        Args:
            port (str): Port name
            baudrate (int, optional): Baud rate for serial communication. Should
            be equals to the defined in SimpleController.ino. Defaults to 115200.
        """
        self.__serialport = serial.Serial(port, baudrate, timeout=1)  # 1 second timeout
        #self.__serialport.write(bytearray([RESET_MESSAGE, 0, 0, 0]))  # Reset
        time.sleep(2)  # Wait for boat reboot
        self.__serialport.write(bytearray([DEVICE_INFO, 0, 0, 0]))  # Request device ID
        byte = self.__serialport.read()
        if not byte:
            raise Exception(
                "Could not get any response from the device.\n"
                + "Make sure you have uploaded SimpleController sktech to your Arduino/ESP32."
            )
        while ord(byte) != DEVICE_INFO:
            # Delete all garbage or ESP32 bootloader
            byte = self.__serialport.read()
            if not byte:
                raise Exception(
                    "Could not get any response from the device.\n"
                    + "Make sure you have uploaded SimpleController sktech to your Arduino/ESP32."
                )
        self.__device = ord(self.__serialport.read())

    def pinMode(self, pin: int, mode: int):
        """Sets mode to a pin

        Args:
            pin (int): Desired pin number
            mode (int): Desired mode. See for allowed modes constants.
        """
        self.__serialport.write(bytearray([SET_PIN_MODE, pin, 0, mode]))

    def digitalWrite(self, pin: int, value: bool):
        """Sends value to digital port

        Args:
            pin (int): Desired pin number
            value (bool): Value
        """
        self.__serialport.write(bytearray([DIGITAL_WRITE, pin, 0, value]))

    def analogWrite(self, pin: int, value: float):
        """Sends value to analog port

        Args:
            pin (int): Desired pin number
            value (float): Float value between 0 and 1
        """
        value = max(0.0, min(value, 1.0))
        data = int(value * 255)  # Converts to 0-255 value
        self.__serialport.write(
            bytearray([ANALOG_WRITE, pin, data >> 8, data & 0x00FF])
        )

    def digitalRead(self, pin: int) -> bool:
        """Reads a digital port

        Args:
            pin (int): Desired pin number

        Returns:
            bool: Value
        """
        self.__serialport.write(bytearray([DIGITAL_READ, pin, 0, 0]))
        byte = self.__serialport.read()
        if not byte:
            return False
        data = ord(byte)
        if data == DIGITAL_READ:
            data = ord(self.__serialport.read())
            if data == pin:
                return int((ord(self.__serialport.read()) << 8) + ord(self.__serialport.read()))
        return False

    def analogRead(self, pin: int) -> float:
        """Reads an analog port

        Args:
            pin (int): Desired pin number

        Returns:
            float: Normalized readed value. Floatting point number between 0 and 1.
        """
        self.__serialport.write(bytearray([ANALOG_READ, pin, 0, 0]))
        byte = self.__serialport.read()
        if not byte:
            return 0
        data = ord(byte)
        if data == ANALOG_READ:
            data = ord(self.__serialport.read())
            if data == pin:
                analog_val = int(
                    (ord(self.__serialport.read()) << 8) + ord(self.__serialport.read())
                )
                if self.__device == ARDUINO:
                    value = round(
                        float(analog_val / 1023), 4
                    )  # Arduino classic analog resolution
                else:
                    value = round(
                        float(analog_val / 4095), 4
                    )  # ESP32 and some Arduinos analog resolution
                    # TODO Fix to hanlde more devices
                return value
        return 0

    def attachServo(self, pin: int):
        """Configure one pin as a servo motor

        Args:
            pin (int): Desired pin number
        """
        # TODO This library supports only one servo. Fix it
        self.__serialport.write(bytearray([SERVO_CONFIG, pin, 0, 0]))

    def servoWrite(self, angle: int):
        """Sends angle to servo motor

        Args:
            angle (int): Desired angle from 0 to 180 degrees.
        """
        angle = max(0, min(angle, 180))
        self.__serialport.write(bytearray([SERVO_WRITE, 0, 0, angle]))

    def close(self):
        """Close serial communication"""
        self.__serialport.close()
