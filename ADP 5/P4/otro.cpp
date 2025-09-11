/**
 * @file otro.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con punteros y arreglos
 * @version 0.1
 * @date 2025-09-11
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>

using namespace std;

void suma(int a, int b, int &resultado) {
    resultado = a + b;
}

int main()
{
    int arrg[3][3] = {{1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9}};

    cout << *(*(arrg + 2) + 1) << endl;
    cout << *(*arrg + 7) << endl;


    int res = 0;
    suma(7, 4, res);
    cout << res << endl;


    return 0;
}
