/**
 * @file friends.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mejores amiguis
 * @version 0.1
 * @date 2025-09-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

using namespace std;

class Gustavo {
    private:
    string nombre;
    string secreto;
    friend class Osvaldo;

    public:
    Gustavo(string nombre) : nombre(nombre) {
        this->secreto = "Me gusta Mariana";
    }

    string getNombre() { return this->nombre; }

    string chismecito(Osvaldo o) {
        return o.secreto;
    }
};

class Osvaldo {
    private:
    string secreto;

    public:
    Osvaldo() {
        this->secreto = "Le voy a bajar su ligue a mi 'compa'";
    }

    string chismecito(Gustavo g) {
        return g.secreto;
    }
};

int main()
{
    Gustavo gustavo("Gustavo");
    Osvaldo osvaldo;

    cout << osvaldo.chismecito(gustavo) << endl;
    
    return 0;
}
