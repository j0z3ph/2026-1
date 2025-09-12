/**
 * @file dinamica.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con memoria dinamica
 * @version 0.1
 * @date 2025-09-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

using namespace std;

class Alumno{

};

int main()
{
    int *entero = new int;
    *entero = 10;

    Alumno *alumno = new Alumno;

    int *arreglo = new int[10];

    for (int i = 0; i < 10; i++)
    {
        arreglo[i] = i + 1;
    }

    cout << "[ ";
    for (int i = 0; i < 10; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << "]" << endl;
    
    

    cout << entero << " - " << *entero << endl;

    delete entero;
    delete alumno;
    delete[] arreglo;
    
    return 0;
}
