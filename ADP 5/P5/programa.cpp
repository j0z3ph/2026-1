/**
 * @file programa.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con memoria y arreglos
 * @version 0.1
 * @date 2025-09-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Cosa {

};

template<typename T>
class Matriz {
    private:
    int filas;
    int columnas;
    T *m;

    public:
    Matriz(int filas, int columnas) {
        if(filas < 1 || columnas < 1) {
            throw exception();
        }

        this->filas = filas;
        this->columnas = columnas;
        this->m = new T[this->filas * this->columnas];
    }

    ~Matriz() {
        delete[] this->m;
    }

    void setValor(int fila, int columna, T valor) {
        this->m[(this->columnas * fila) + columna] = valor;
    }

    T getValor(int fila, int columna) {
        return this->m[(this->columnas * fila) + columna];
    }

    friend ostream& operator<<(ostream& os, const Matriz& m) {
        for (int i = 0; i < m.filas * m.columnas; i++)
        {
            if(i%m.columnas == 0) {
                os << endl;
            }
            os << m.m[i] << " ";
        }
        return os;
    }

};


int main()
{
    for (;;)
    {
        Matriz<Cosa> m1(3,4);
    }
    



    Matriz<int> m(4,3);
    int cont = 1;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m.setValor(i,j,cont++);
        } 
    }
    
    cout << m << endl;
    
    
    return 0;
}
