import simplecontroller as sc
import time 

device = sc.Board("/dev/cu.usbserial-0001")
device.pinMode(2, sc.OUTPUT)
#device.pinMode(13, sc.INPUT_PULLUP)
time.sleep(0.1)
while True:
    device.digitalWrite(2, True)
    time.sleep(1)
    device.digitalWrite(2, False)
    time.sleep(1)
    #device.digitalWrite(2, not device.digitalRead(13))
    