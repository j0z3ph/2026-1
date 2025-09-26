/**
 * @file herencia.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con herencia
 * @version 0.1
 * @date 2025-09-22
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>
#include <stdexcept>
#include "figuras.hpp"

using namespace std;
using namespace fig;

int main()
{
    Rectangulo r1(4, 5);
    cout << r1.area() << endl;

    Triangulo t1(3, 6);
    cout << t1.area() << endl;

    return 0;
}
