/**
 * @file herencia.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con la herencia
 * @version 0.1
 * @date 2025-09-23
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

    Rectangulo rect(5, 10);
    cout << rect.area() << endl;

    Triangulo tri(5, 10);
    cout << tri.area() << endl;

    return 0;
}
