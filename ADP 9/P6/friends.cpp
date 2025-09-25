/**
 * @file friends.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Que paso con los amigos?
 * @version 0.1
 * @date 2025-09-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

using namespace std;


class Osvaldo {
    private:
    string nombre;
    string secreto;
    friend class Josthin;

    public:
    Osvaldo(string nombre) : nombre(nombre) {
        this->secreto = "Le voy al America";
    }
    void setNombre(string nombre) { this->nombre = nombre; }
    string getNombre() { return this->nombre; }

    string chismecito(Josthin j) {
        return j.secreto;
    }

};

class Josthin {
    private:
    string secreto;
    
    public:
    Josthin() {
        this->secreto = "Yo le voy a las Chivas";
    }

    string chismecito(Osvaldo p) {
        return p.secreto;
    }
};

int main()
{
    Osvaldo osvaldo("Osvaldo");
    Josthin josthin;
    cout << josthin.chismecito(osvaldo) << endl;
    
    
    return 0;
}
