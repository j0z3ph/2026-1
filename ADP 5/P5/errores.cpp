/**
 * @file errores.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Manejo de Excepciones
 * @version 0.1
 * @date 2025-09-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = 0;

    try
    {
        if(b == 0) {
            throw exception();
        }
        int c = a / b;
    }
    catch(const std::exception& e)
    {
        cout << "Upss" << endl;
        //std::cerr << e.what() << '\n';
    }
    
    
    
    return 0;
}
