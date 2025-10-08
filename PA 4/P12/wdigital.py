import serial

device = serial.Serial('/dev/cu.usbserial-1410', 115200, timeout=1)

if device.is_open:
    command = "n"
    while not command.startswith("q"):
        command = input('Escriba un comando[on/off/q]:')
        device.write((command + "\n").encode())
        response = device.readline().decode()
        print(response)
        
    device.close()
