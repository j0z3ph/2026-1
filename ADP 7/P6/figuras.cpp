
#include <stdexcept>
#include "figuras.hpp"

using namespace std;
using namespace fig;

Figura::Figura(float base, float altura)
{
    if (base <= 0.0f || altura <= 0.0f)
    {
        throw runtime_error("Que tonoto eres, eso no se puede");
    }

    this->base = base;
    this->altura = altura;
}

// Getters
float Figura::getBase() { return this->base; }
float Figura::getAltura() { return this->altura; }

// Sobreescritura
// Polimorfismo
float Rectangulo::area()
{
    return this->base * this->altura;
}

// Sobre escritura
// Polimorfismo
float Triangulo::area()
{
    return (this->base * this->altura) / 2.0f;
}
