/**
 * @file matrix.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Matrix
 * @version 0.1
 * @date 2025-09-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>
#include<stdexcept>

using namespace std;

template<typename T>
class Matriz {
    private:
    int filas;
    int columnas;
    T *data;

    public:
    Matriz(int filas, int columnas) {

        if(filas < 1 || columnas < 1) {
            throw runtime_error("A caso eres ^%$#&*$#& >:[");
        }

        this->filas = filas;
        this->columnas = columnas;
        this->data = new T[this->filas * this->columnas];
    }

    ~Matriz() {
        delete[] this->data;
    }

    void setValor(int fila, int columna, T valor){
        this->data[(this->columnas * fila) + columna] = valor;
    }

    T getValor(int fila, int columna) {
        return this->data[(this->columnas * fila) + columna];
    }


    friend ostream& operator<<(ostream &os, const Matriz &m) {
        for (int i = 0; i < m.filas * m.columnas; i++)
        {
            if(i%m.columnas == 0) {
                os << endl;
            }
            os << m.data[i] << " ";
        }
        return os;
    }

};

class Cosa {

};

int main()
{
    /*for (;;)
    {
        Matriz a(100,100);
    }*/
    


    try
    {
        Matriz<int> m(4,3);
        int cont = 1;

        for (int f = 0; f < 4; f++)
        {
            for (int c = 0; c < 3; c++)
            {
                m.setValor(f,c,cont++);
            }   
        }

        cout << m << endl;
        
        
    }
    catch(const std::runtime_error& e)
    {
        cout << "Ja, tonto" << endl;
        //std::cerr << e.what() << '\n';
    }
    
    
    
    return 0;
}
