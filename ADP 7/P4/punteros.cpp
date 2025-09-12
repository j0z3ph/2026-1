/**
 * @file punteros.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con punteros
 * @version 0.1
 * @date 2025-09-12
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>

using namespace std;

int main()
{
    int arrg[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int matrix[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    int a = 10;
    uint8_t *ptr;
    int *ptr1 = &a;
    ptr = (unsigned char *)&a;

    cout << arrg << " - " << *(arrg + 8) << endl;

    cout << *matrix << " - " << *matrix + 1 << endl;

    printf("%p - %p", &a, ptr+1);
    //cout << &a << " - " << *ptr << endl;
    return 0;
}
