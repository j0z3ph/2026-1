/**
 * @file busqueda_no_binaria.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Busqueda LGBTQ+HDMI
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
#define N 10000

bool busqueda_no_binaria(int arrg[], int n, int x) {
    static int ini = 0;
    static int fin = N - 1;
    static int m;
    static bool encontrado = false;
    static int cont = 0;
    if(ini <= fin) {
        cont++;
        m = (((fin - ini) + 1) / 2) + ini;
        if(arrg[m] == x) {
            encontrado = true;
            printf("Numero de comparaciones: %i\n", cont);
            return encontrado;
        } else if(x > arrg[m]) {
            ini = m + 1;
        } else {
            fin = m - 1;
        }
        busqueda_no_binaria(arrg, n, x);
        //printf("Numero de comparaciones: %i\n", cont);
    }
    return encontrado;
}


int main()
{
    int arrg[N];
    int aux;
    int x;
    int ini = 0;
    int fin = N - 1;
    int m = (((fin - ini) + 1) / 2) + ini;
    bool encontrado = false;

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        arrg[i] = rand() % (N * 20);
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - (i + 1); j++)
        {
            if (arrg[j] > arrg[j + 1])
            {
                aux = arrg[j];
                arrg[j] = arrg[j + 1];
                arrg[j + 1] = aux;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%i ", arrg[i]);
    }
    printf("\n");

    printf("Usuario, qué número deseas encontrar?🤔 ");
    scanf("%i", &x);

    encontrado = busqueda_no_binaria(arrg, N, x);

    if(encontrado) {
        printf("Felicidades, eres el ganador 🥳\n");
    } else {
        printf("Perdedor, suerte en la proxima... vida 💩\n");
    } 

    return 0;
}
