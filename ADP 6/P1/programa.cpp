/**
 * @file programa.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer programa en C++ :>
 * @version 0.1
 * @date 2025-08-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

using namespace std;

int main()
{
    int edad;
    string nombre;

    cout << "Usuario, ingresa tu nombre: ";
    getline(cin, nombre);

    cout << "Usuario, ingresa tu edad: ";
    cin >> edad;
    cout << nombre << ", tu edad es " << edad << "." << endl;

    return 0;
}
