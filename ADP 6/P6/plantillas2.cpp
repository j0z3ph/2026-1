/**
 * @file plantillas2.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con plantillas 2
 * @version 0.1
 * @date 2025-09-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

using namespace std;

template<typename T>
T suma(T a, T b) {
    return a + b;
}

class Cosa {

};

int main()
{
    cout << suma<int>(3,4) << endl;
    return 0;
}
