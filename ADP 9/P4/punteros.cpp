/**
 * @file punteros.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con punteros
 * @version 0.1
 * @date 2025-09-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

using namespace std;

void suma(int a, int b, int &res) {
    res = a+b;
}

int main()
{
    int res;

    suma(8,12, res);
    cout << res << endl;
    
    return 0;
}
