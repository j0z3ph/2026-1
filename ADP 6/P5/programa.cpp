/**
 * @file programa.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con cosas
 * @version 0.1
 * @date 2025-09-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include <vector>
#include <list>

using namespace std;
class Cosa{

};


int main()
{

    vector<Cosa> listaDeCosas;

    vector<int> lista;
    list<int> lista2;

    lista2.push_back(100);
    lista2.push_back(200);


    for (auto &&i : lista2)
    {
        cout << i << " ";
    }
    


    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(3);
    lista.push_back(4);

    //lista.emplace_back(5);

    for (int i = 0; i < lista.size(); i++)
    {
        cout << lista[i] << " ";
    }
    
    
    return 0;
}
