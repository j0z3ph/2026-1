/**
 * @file amigos.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mejores amigos
 * @version 0.1
 * @date 2025-09-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

using namespace std;

class Daniel {
    private:
    string nombre;
    string secreto;
    friend class David;

    public:

    Daniel(string nombre) {
        this->nombre = nombre;
        this->secreto = "Reprobe comunicacion oral y escrita XD";
    }

    string getNombre() { return this->nombre; }

    string chismecito(David d) {
        return d.secreto;
    }
};

class David {
    private:
    string secreto;

    public:
    David() {
        this->secreto = "Choque el carro de daniel XD";
    }

    string chismecito(Daniel d) {
        return d.secreto;
    }
};

int main()
{
    Daniel daniel("Daniel");
    David david;

    cout << david.chismecito(daniel) << endl;
    cout << daniel.chismecito(david) << endl;
    
    return 0;
}
