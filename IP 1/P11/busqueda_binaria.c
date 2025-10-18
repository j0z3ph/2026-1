/**
 * @file busqueda_binaria.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que realiza una busqueda binaria
 * @version 0.1
 * @date 2025-10-17
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100000

int main()
{
    int arrg[N];
    int aux;
    int ini = 0;
    int fin = N-1;
    int m;
    int x;
    bool encontrado = false;

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        arrg[i] = rand() % (N * 10);
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (arrg[j] > arrg[j + 1])
            {
                aux = arrg[j + 1];
                arrg[j + 1] = arrg[j];
                arrg[j] = aux;
            }
        }
    }

    /*for (int i = 0; i < N; i++)
    {
        printf("%d ", arrg[i]);
    }*/


    printf("\nUsuario, ingresa un valor 🤬 ");
    scanf("%i", &x);

    while(ini <= fin) {
        m = ((fin - ini)/2) + ini;
        if(arrg[m] == x) {
            encontrado = true;
            break;
        } else if(arrg[m] < x) {
            ini = m + 1;
        } else {
            fin = m - 1;
        }
    }

    if(encontrado) {
        printf("Felicidades 🥳 eres el mejor 👅");
    } else {
        printf("Eres un perdedor 🖕🏻");
    }


    return 0;
}
