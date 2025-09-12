/**
 * @file programa.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con la sobrecarga de operadores
 * @version 0.1
 * @date 2025-09-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

using namespace std;

class Punto{
    private:
    int x;
    int y;

    public:
    Punto(int x, int y) : x(x), y(y) { }

    // Getters
    int getX() { return this->x; }
    int getY() { return this->y; }

    // Setters
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    Punto operator+(const Punto &p){
        Punto presultante(x + p.x, y + p.y);
        return presultante;
    }

    friend ostream& operator<<(ostream &os, const Punto &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};


int main()
{
    Punto p1(1,5);
    Punto p2(34,6);
    Punto p3 = p1 + p2;
    
    cout << p3 << endl;

    return 0;
}
