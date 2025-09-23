/**
 * @file herencia.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con herencia
 * @version 0.1
 * @date 2025-09-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>
#include<stdexcept>

using namespace std;

class Figura {
    protected:
    float base;
    float altura;

    public:
    Figura(float base, float altura) {
        if(base <= 0.0f || altura <= 0.0f) {
            throw runtime_error("No seas &^*#%* >:[");
        }
        this->base = base;
        this->altura = altura;
    }

    //Getters
    float getBase() { return this->base; }
    float getAltura() { return this->altura; }

    // Setters
    void setBase(int base) { this->base = base; }
    void setAltura(int altura) { this->altura = altura; }

    // Metodo
    float area() {
        return this->base * this->altura;
    }
};


class Rectangulo : public Figura {
    public:
    Rectangulo(float base, float altura) : Figura(base, altura)
    {

    }

    float perimetro() {
        return this->base * 2 + this->altura* 2;
    }
};

class Triangulo : public Figura {
    public:
    Triangulo(float base, float altura) : Figura(base, altura)
    {

    }
    // Polimorfismo
    // Sobreescritura
    float area() {
        return (this->base * this->altura) / 2.0f;
    }
    
};


int main()
{

    Rectangulo r1(4,5);
    cout << r1.area() << endl;


    Triangulo t1(3,6);
    cout << t1.area() << endl ;
    
    
    return 0;
}
