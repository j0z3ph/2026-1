/**
 * @file herencia.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con los terrenos del abuelo
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

    try
    {
        Rectangulo rect(-5, 6);
        // rect.setAltura(10);
        // rect.setBase(8);

        cout << rect.area() << endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
    }

    Triangulo tri(5, 6);

    // tri.setAltura(12);
    // tri.setBase(3);
    cout << tri.area() << endl;

    return 0;
}
