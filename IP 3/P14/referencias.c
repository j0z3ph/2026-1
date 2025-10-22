/**
 * @file referencias.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Otra vez funciones 🙄
 * @version 0.1
 * @date 2025-10-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int suma_ref(int *a, int *b) {
    (*a)++;
    (*b)++;
    return *a + *b;
}

int suma(int a, int b) {
    a++;
    b++;
    return a + b;
}

int main()
{
    int a = 10;
    int b = 500;

    int r = suma_ref(&a, &b);

    printf("%i\n%i\n%i\n", a, b, r);
    
    return 0;
}
