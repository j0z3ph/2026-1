/**
 * @file herencia.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con herencia
 * @version 0.1
 * @date 2025-09-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include <stdexcept>

using namespace std;

class Figura {
protected:
    double base;
    double altura;

    public:
    Figura(double base, double altura) {
        if(base <= 0.0 || altura <= 0.0) {
            throw runtime_error("No seas tonto");
        }

        this->altura = altura;
        this->base = base;
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
    Rectangulo(double base, double altura) : Figura(base, altura)
    {

    }

    double perimetro(){
        return this->base * 2 + this->altura * 2;
    }
};

class Triangulo : public Figura {
    public:
    Triangulo(double base, double altura) : Figura(base, altura)
    {

    }
    // Polimorfismo
    // Sobre escritura
    double area() {
        return (this->base * this->altura) / 2.0;
    }

};


int main()
{
    try
    {
        Rectangulo rect(5,6);
        cout << rect.area() << endl;

        Triangulo tri(5,6);
        cout << tri.area() << endl;

    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    
    return 0;
}
