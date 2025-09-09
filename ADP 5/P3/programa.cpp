/**
 * @file programa.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer clase :>
 * @version 0.1
 * @date 2025-09-09
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
    Rectangulo(int base, int altura) {
        this->base = (double)base;
        this->altura = (double)altura;
    }

    // Destructor
    ~Rectangulo() {
        cout << "Ya me mori X~X" << endl;
    }

    // Getters
    double getBase(){ return base; }
    double getAltura() { return altura; }

    // Setter
    void setBase(double base) { this->base = base; }
    void setAltura(double altura) { this->altura = altura; }

    // Metodos
    double area() {
        return base * altura;
    }
    
};


int main()
{
    Rectangulo rect(5.2, 2.5);
  
    cout << "El area es " << rect.area() << endl;
    
    return 0;
}
