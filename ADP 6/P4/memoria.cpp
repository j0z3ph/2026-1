/**
 * @file memoria.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando
 * @version 0.1
 * @date 2025-09-11
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>

using namespace std;

void nini(){
    int *a = new int[1000];
    delete[] a;
}

int main()
{

    while(1) nini();
    return 0;
}
