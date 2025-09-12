/**
 * @file punteros.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con punteros
 * @version 0.1
 * @date 2025-09-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

using namespace std;

int main()
{
    int arrg[10] = {1,2,3,4,5,6,7,8,9,0};
    int matrix[3][3] = {{1,2,3}, 
                        {4,5,6}, 
                        {7,8,9}};

    cout << *(arrg + 8) << endl;

    cout << *(*matrix + 5)<< endl;
    
    return 0;
}
