COMPILER=gcc
SERIAL=serial.c
SERIAL_H=serial.h
SCONTROLLER=simplecontroller.c
SCONTROLLER_H=simplecontroller.h

run: test.exe
	./test.exe

test.exe: test.c $(SERIAL_H) $(SERIAL) $(SCONTROLLER) $(SCONTROLLER_H)
	$(COMPILER) -o test.exe test.c $(SERIAL) $(SCONTROLLER)

