

class Figura {
protected:
    double base;
    double altura;

    public:
    Figura(double base, double altura) {
        if(base <= 0.0 || altura <= 0.0) {
            throw runtime_error("No seas tonto");
        }

        this->altura = altura;
        this->base = base;
    }

    // Getters
    double getBase() { return this->base; }
    double getAltura() { return this->altura; }

    // Setters
    //void setBase(double base) { this->base = base; }
    //void setAltura(double altura) { this->altura = altura; }

    // Metodos
    virtual double area() = 0;

};

class Rectangulo : public Figura {
    public:
    Rectangulo(double base, double altura) : Figura(base, altura)
    {

    }

    double area() {
        return this->base * this->altura;
    }


    double perimetro(){
        return this->base * 2 + this->altura * 2;
    }
};

class Triangulo : public Figura {
    public:
    Triangulo(double base, double altura) : Figura(base, altura)
    {

    }
    // Polimorfismo
    // Sobre escritura
    double area() {
        return (this->base * this->altura) / 2.0;
    }

    

};


