/**
 * @file memoria.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con memoria dinamica
 * @version 0.1
 * @date 2025-09-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>

using namespace std;

int main()
{
    int *entero = new int;
    *entero = 10;

    int *arr = new int[10];

    cout << entero << " - " << *entero << endl;

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
    }
    
    delete entero; // Liberacion de una variable
    delete[] arr; // Liberacion de un arreglo
    
    return 0;
}
