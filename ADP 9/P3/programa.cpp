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
#include <iostream>

using namespace std;

class Rectangulo
{
    private:
    // Atributos
    int base;
    int altura;

    public:
    // Constructores
    Rectangulo(int base, int altura) {
        this->base = base;
        this->altura = altura;
    }

    // Destructor
    ~Rectangulo() {
        cout << "Ya me mori X~X" << endl;
    }


    // Getters
    int getBase() { return base; }
    int getAltura() { return altura; }

    // Setters
    void setBase(int base) { this->base = base; }
    void setAltura(int altura) { this->altura = altura; }

    // Metodos
    int area()
    {
        return base * altura;
    }
};

int main()
{
    Rectangulo rect1(10, 5);
    
    cout << "El area es " << rect1.area() << endl;

    return 0;
}
