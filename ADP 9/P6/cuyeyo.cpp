/**
 * @file cuyeyo.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con la herencia multiple
 * @version 0.1
 * @date 2025-09-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

using namespace std;

class Mama {
    public:
    void habla() {
        cout << "Soy la mama";
    }
};

class Papa {
    public:
    void habla() {
        cout << "Soy el papa";
    }
};

class Cuyeyo {
    public:
    void habla() {
        cout << "Padre es el que cria";
    }
};

class Hije : public Mama, public Papa, public Cuyeyo {

};

int main()
{
    Hije hije;
    hije.habla();

    return 0;
}
