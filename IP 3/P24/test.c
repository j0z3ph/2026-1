/**
 * @file test.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer blink
 * @version 0.1
 * @date 2025-11-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "simplecontroller.h"

int main()
{
    Board *b = connectDevice("COM6", B115200);
    b->pinMode(b, 2, OUTPUT);
    
    while (1)
    {
        b->digitalWrite(b, 2, 1),
        Sleep(1000);
        b->digitalWrite(b, 2, 0),
        Sleep(1000);
    }

    b->closeDevice(b);
    return 0;
}
