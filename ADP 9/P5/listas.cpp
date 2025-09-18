/**
 * @file listas.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Manejo de listas
 * @version 0.1
 * @date 2025-09-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Persona {


};

int main()
{
    vector<Persona> lista;
    list<int> lista2;

    lista2.push_back(3);

    for(auto i: lista2){
        cout << i << endl;
    }
    
    lista.push_back(Persona());
    lista.push_back(Persona());
    lista.push_back(Persona());

    //lista.emplace_back(Persona());
    

    for (int i = 0; i < lista.size(); i++)
    {
        //cout << lista[i] << " ";
    }
    
    
    
    return 0;
}
