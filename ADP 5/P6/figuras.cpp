
#include "figuras.hpp"
#include <stdexcept>

using namespace std;
using namespace fig;

Figura::Figura(double altura, double base)
{
    if (altura <= 0.0 || base <= 0.0)
    {
        throw runtime_error("Eres tonto.");
    }
    this->base = base;
    this->altura = altura;
}

// Getters
double Figura::getBase() { return this->base; }
double Figura::getAltura() { return this->altura; }


// Polimorfismo
// Sobre escritura
double Rectangulo::area()
{
    return (this->base * this->altura);
}

double Rectangulo::perimetro()
{
    return this->base * 2 + this->altura * 2;
}

// Polimorfismo
// Sobre escritura
double Triangulo::area()
{
    return (this->base * this->altura) / 2.0;
}
