/**
 * @file plantillas.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief JUgando con plantillas
 * @version 0.1
 * @date 2025-09-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

using namespace std;

template<typename T>
class Matrix {
    private:
    int filas;
    int columnas;
    T *matrix;

    public:
    Matrix(int filas, int columnas) {
        this->filas = filas;
        this->columnas = columnas;
        this->matrix = new T[filas * columnas];
    }

    ~Matrix() {
        delete[] this->matrix;
    }

    void setValor(int fila, int columna, T valor) {
        this->matrix[(fila * this->columnas) + columna] = valor;
    }

    T getValor(int fila, int columna) {
        return matrix[(fila * this->columnas) + columna];
    }

    friend ostream& operator<<(ostream &os, const Matrix &m) {
        for (int i = 0; i < (m.filas * m.columnas); i++)
        {
            if(i%m.columnas == 0) {
                os << endl;
            }
            os << m.matrix[i] << " ";
        }
        return os;
    }


};


template<typename T, typename S>
S suma(T a, T b) {
    return (S)(a + b);
}

int main()
{
    suma<float, int>(5.6, 5.6);

    Matrix<float> m(3,4);
    
    return 0;
}
