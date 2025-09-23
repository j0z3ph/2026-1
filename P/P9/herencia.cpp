#include <iostream>

using namespace std;

class Mama
{
public:
    void habla()
    {
        cout << "Soy la mama" << endl;
    }
};

class Papa
{
public:
    void habla()
    {
        cout << "Soy el papa" << endl;
    }
};

class Cuyeyo
{
public:
    void habla()
    {
        cout << "Padre es el que cria" << endl;
    }
};

class Hije : public Mama, public Papa, public Cuyeyo {

};

int main()
{
    Hije hije;

    hije.habla();

    return 0;
}
