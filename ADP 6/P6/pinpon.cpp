/**
 * @file pinpon.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Herencia multiple
 * @version 0.1
 * @date 2025-09-22
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
        cout << "Padre el que cria";
    }
};

class Hije : public Mama, public Papa, public Cuyeyo {

};

int main()
{
    Hije hije;
    hije.Mama::habla();
    
    return 0;
}
