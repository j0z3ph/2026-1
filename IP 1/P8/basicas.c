
#include<stdarg.h>
// Definiciones

int suma(int a, int b) {
    int resultado;
    resultado = a + b;
    return resultado;
}

int multiplica(int a, int b) {
    return a * b;
}

float division(int dividendo, int divisor) {
    return (float)dividendo / (float)divisor;
}


int suma_variadica(int n, ...) {
    va_list args;
    va_start(args, n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += va_arg(args, int);
    }
    va_end(args);
    return res;
}