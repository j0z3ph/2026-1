/**
 * @file nini.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Nada
 * @version 0.1
 * @date 2025-09-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

void nada(){
    int *a = new int[100];
    delete[] a;
}

int main()
{
    while(100) nada();
    
    return 0;
}
