/**
 * @file herencia.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con la herencia
 * @version 0.1
 * @date 2025-09-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>
#include<stdexcept>

using namespace std;

class Figura {
protected:
    double base;
    double altura;

    public:
    Figura(double altura, double base) {
        if(altura <= 0.0 || base <= 0.0) {
            throw runtime_error("Eres tonto.");
        }
        this->base = base;
        this->altura = altura;
    }


    // Getters
    double getBase() { return this->base; }
    double getAltura() { return this->altura; }

    // Setters
    void setBase(double base) { this->base = base; }
    void setAltura(double altura) { this->altura = altura; }

    // Metodos
    double area() {
        return this->base * this->altura;
    }
};

class Rectangulo : public Figura {
    
    public:
    Rectangulo(double base, double altura) : Figura(altura, base)
    {

    }


    double perimetro() {
        return this->base * 2 + this->altura * 2;
    }
};

class Triangulo : public Figura {
    public:
    Triangulo(double base, double altura) : Figura(altura, base) {

    }

    // Polimorfismo
    // Sobre escritura
    double area() {
        return (this->base * this->altura) / 2.0;
    }
};


int main()
{

    Rectangulo rect(5,10);
    cout << rect.area() << endl;
    
    Triangulo tri(5,-10);
    cout << tri.area() << endl;
    
    return 0;
}
