/**
 * @file amigos.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Conociendo a los verdaderos amigos
 * @version 0.1
 * @date 2025-09-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

using namespace std;

class Tiger {
    private:
    string secreto;
    friend class Erick;

    public:
    Tiger() {
        this->secreto = "Quiero mucho a mi mejor amigo Erick";
    }
    string chismecito(Erick e) {
        return e.secreto;
    }

    
};

class Erick {
    private:
    string secreto;

    public:
    Erick() {
        this->secreto = "Me gusta la novia de mi mejor amigo Tiger";
    }

    string chismecito(Tiger t) {
        return t.secreto;
    }

};


int main()
{
    Erick e;
    Tiger t;

    cout << e.chismecito(t) << endl;
    
    
    return 0;
}
