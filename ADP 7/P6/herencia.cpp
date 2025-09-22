/**
 * @file herencia.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con los terrenos del abuelo
 * @version 0.1
 * @date 2025-09-22
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>

using namespace std;

class Figura {
protected:
    float base;
    float altura;

public:
    Figura(float base, float altura)
    {
        this->base = base;
        this->altura = altura;
    }

    // Getters
    float getBase() { return this->base; }
    float getAltura() { return this->altura; }

    // Setters
    void setBase(float base) { this->base = base; }
    void setAltura(float altura) { this->altura = altura; }

    // Metodo
    float area()
    {
        return this->base * this->altura;
    }

};


class Rectangulo : public Figura
{
    public:
    Rectangulo(float base, float altura) : Figura(base, altura) {
        
    }

};

class Triangulo : public Figura
{

    public:
    Triangulo(float base, float altura) : Figura(base, altura) {
        
    }

    // Sobre escritura
    // Polimorfismo
    float area()
    {
        return (this->base * this->altura) / 2.0f;
    }
};



int main()
{
    Rectangulo rect(5,6);
    //rect.setAltura(10);
    //rect.setBase(8);
    
    cout << rect.area() << endl;

    Triangulo tri(5,6);

    //tri.setAltura(12);
    //tri.setBase(3);
    cout << tri.area() << endl;

    return 0;
}
