/**
 * @file programa.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer clase :>
 * @version 0.1
 * @date 2025-09-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

using namespace std;

class Estudiante {
    private:
    // Atributos
    string boleta;
    string nombre;
    string apellido1;
    string apellido2;

    public:

    // Constructor
    Estudiante(string nombre, string apellidoPaterno,
    string apellidoMaterno, string boleta) {
        this->nombre = nombre;
        this->apellido1 = apellidoPaterno;
        this->apellido2 = apellidoMaterno;
        this->boleta = boleta;
    }
    Estudiante(string nombre, string apellidoPaterno, string boleta) {
        this->nombre = nombre;
        this->apellido1 = apellidoPaterno;
        this->apellido2 = "";
        this->boleta = boleta;
    }

    // Destructor
    ~Estudiante() {
        cout << "Me mori :(" << endl;
    }


    // Getters
    string getNombre() { return nombre; }
    string getBoleta() { return boleta; }
    string getApellidoPaterno() { return apellido1; }
    string getApellidoMaterno() { return apellido2; }

    // Setters
    void setNombre(string nombre) { this->nombre = nombre; }
    void setBoleta(string boleta) { this->boleta = boleta; }
    void setApellidoPaterno(string ap) { this->apellido1 = ap; }
    void setApellidoMaterno(string am) { this->apellido2 = am; }
    
    // Metodos
    void presentate() {
        cout << "Hola, mi nombre es " << this->nombre << " " << this->apellido1 << " " << this->apellido2 << ", y mi boleta es " << this->boleta << "." << endl;
    }
};



int main()
{
    Estudiante estudiante1("Kevin", "Barrios", "Ayala", "8736487234");
    
    {
        Estudiante e("","","");
    }
    
    
    estudiante1.presentate();
    return 0;
}
