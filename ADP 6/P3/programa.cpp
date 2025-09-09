/**
 * @file programa.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer clase :>
 * @version 0.1
 * @date 2025-09-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

using namespace std;

class Rectangulo {
    private:
    // Atributos
    double base;
    double altura;
    
    public:

    // Constructor 
    Rectangulo(double base, double altura) {
        this->base = base;
        this->altura = altura;
    }

    ~Rectangulo(){
        cout << "Ya me mori X~X" << endl;
    }

    // Getters
    double getAltura() { return altura; }
    double getBase() { return base; }

    // Setters
    void setAltura(double altura) { this->altura = altura; }
    void setBase(double base) { this->base = base; }

    // Metodos
    double area() {
        return base * altura;
    }
};


int main()
{
    Rectangulo r1(6.7, 8.24);

    cout << "El area es " << r1.area() << endl;


    
    return 0;
}
