/**
 * @file mas_dinamico.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2025-09-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

using namespace std;

class Matrix {
    private:
    int filas;
    int columnas;
    int *matrix;

    public:
    Matrix(int filas, int columnas) {
        this->filas = filas;
        this->columnas = columnas;
        this->matrix = new int[filas * columnas];
    }

    ~Matrix() {
        delete[] this->matrix;
    }

    void setValor(int fila, int columna, int valor) {
        this->matrix[(fila * this->columnas) + columna] = valor;
    }

    int getValor(int fila, int columna) {
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

int main()
{

    for (;;)
    {
        Matrix m(1,2);
    }
    


    Matrix m(4, 3);
    int cont = 1;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m.setValor(i,j,cont++);
        }
    }

    cout << m;
    

    
    return 0;
}
