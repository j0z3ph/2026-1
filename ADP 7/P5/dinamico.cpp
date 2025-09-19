/**
 * @file dinamico.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con memoria dinamica
 * @version 0.1
 * @date 2025-09-19
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Cosa
{
};

int main()
{

    vector<int> lista;
    list<int> list2;


    list2.push_back(1);
    list2.push_back(2);

    for (auto &&i : list2)
    {
        cout << i << " " << endl;
    }
    return 0;
    

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

    {
        int a;
    }

    {
        int *b = new int;
        delete b;
    }

    Cosa *c = new Cosa();

    Cosa *arrc = new Cosa[100];

    int *arrg = new int[10];
    int *entero = new int;

    for (int i = 0; i < 10; i++)
    {
        arrg[i] = i;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arrg[i] << " ";
    }

    *entero = 10;

    cout << entero << " - " << *entero << endl;

    delete c;
    delete entero;

    delete[] arrc;
    delete[] arrg;

    return 0;
}
