/**
 * @file mas_fors.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Infinitos
 * @version 0.1
 * @date 2025-09-10
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{

    for (int cont = 1; cont <= 10; cont++)
    {
        if (cont % 2 != 0)
            continue;
        printf("Hola %i\n", cont);
    }

    return 0;
}
