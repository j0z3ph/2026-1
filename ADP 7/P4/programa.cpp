/**
 * @file programa.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con sobrecarga de operadores
 * @version 0.1
 * @date 2025-09-12
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>

using namespace std;

class Punto
{
private:
    int x;
    int y;

public:
    // Constructor
    Punto(int x, int y) : x(x), y(y) {}

    // Getters
    int getX() { return this->x; }
    int getY() { return this->y; }

    // Setters
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    // Sobrecarga del operador
    Punto operator*(const Punto &p)
    {
        Punto punto_resultante(x * p.x, y * p.y);
        return punto_resultante;
    }

    friend ostream& operator<<(ostream &os, const Punto &p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main()
{
    Punto p1(3, 4);
    Punto p2(8, 5);
    Punto p3 = p1 * p2;

    cout << p3 << endl;

    return 0;
}
