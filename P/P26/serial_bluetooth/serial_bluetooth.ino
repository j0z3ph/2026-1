#include "BluetoothSerial.h"
#define LED 2

String receivedString;
String device_name = "ESP32-Java";
BluetoothSerial SerialBT;

void setup() {
  SerialBT.begin(device_name);  //Bluetooth device name
  //SerialBT.deleteAllBondedDevices(); // Uncomment this to delete paired devices; Must be called after begin
  pinMode(LED, OUTPUT);
}

void loop() {
  if (SerialBT.available() > 0) {
    receivedString = SerialBT.readStringUntil('\n');
    if (receivedString.equals("on") || receivedString.equals("ON")) {
      digitalWrite(LED, HIGH);
      SerialBT.print("Led encendido.\n");
    } else if (receivedString.equals("off") || receivedString.equals("OFF")) {
      digitalWrite(LED, LOW);
      SerialBT.print("Led apagado.\n");
    } else if (receivedString.equals("q") || receivedString.equals("Q")) {
      SerialBT.print("Adios.\n");
    } else {
      SerialBT.print("Comando no valido.\n");
    }
  }
}