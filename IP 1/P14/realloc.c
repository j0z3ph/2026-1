/**
 * @file realloc.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con realloc
 * @version 0.1
 * @date 2025-10-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *arrg;

    arrg = malloc(sizeof(int)*10);
    for (int i = 0; i < 10; i++)
    {
        printf("%p\n", arrg + i);
    }
    for (int i = 0; i < 10; i++)
    {
        *(arrg + i) = i + 1;
    }


    printf("---------------\n");
    arrg = realloc(arrg, sizeof(int) * 20);
    for (int i = 0; i < 10; i++)
    {
        printf("%p\n", arrg + i);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%i ", *(arrg + i));
    }

    free(arrg);
    
    
    return 0;
}
