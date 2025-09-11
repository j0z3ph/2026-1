/**
 * @file dinamico.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con punteros y memoria dinamica
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
    int *entero;
    int *arreglo;
    Alumno *al;
    al = new Alumno;

    entero = new int;
    arreglo = new int[10];

    for (int i = 0; i < 10; i++)
    {
        arreglo[i] = i+1;
    }
    
    cout << "[ ";
    for (int i = 0; i < 10; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << "]" << endl;
    

    *entero = 10;
    cout << entero << endl << *entero << endl;
    cout << sizeof(arreglo)<<endl;

    delete entero;
    delete al;
    delete[] arreglo;


    
    return 0;
}
