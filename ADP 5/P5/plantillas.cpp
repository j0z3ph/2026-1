/**
 * @file plantillas.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con plantillas
 * @version 0.1
 * @date 2025-09-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

using namespace std;

template<typename T, typename S>
S suma(T a, T b) {
    return (S)(a + b);
}

int main()
{
    cout << suma<double, int>(4,5);
    
    return 0;
}
