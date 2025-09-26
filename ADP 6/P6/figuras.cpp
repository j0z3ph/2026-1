
#include <stdexcept>
#include "figuras.hpp"

using namespace std;
using namespace fig;

Figura::Figura(float base, float altura)
{
    if (base <= 0.0f || altura <= 0.0f)
    {
        throw runtime_error("No seas &^*#%* >:[");
    }
    this->base = base;
    this->altura = altura;
}

// Getters
float Figura::getBase() { return this->base; }
float Figura::getAltura() { return this->altura; }

// Polimorfismo
// Sobreescritura
float Rectangulo::area()
{
    return (this->base * this->altura);
}

float Rectangulo::perimetro()
{
    return this->base * 2 + this->altura * 2;
}

// Polimorfismo
// Sobreescritura
float Triangulo::area()
{
    return (this->base * this->altura) / 2.0f;
}
