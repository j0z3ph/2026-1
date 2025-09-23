class Figura {
    protected double base;
    protected double altura;

    Figura(double base, double altura) {
        this.altura = altura;
        this.base = base;
    }

    // Setters
    public void setBase(double base) {
        this.base = base;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    // Getters
    public double getBase() {
        return base;
    }

    public double getAltura() {
        return altura;
    }

    // Metodo
    public double area() {
        return this.base * this.altura;
    }
}

class Rectangulo extends Figura {
    
    Rectangulo(double base, double altura) {
        super(base, altura);
    }
}

class Triangulo extends Figura {

    //private int valor;
    Triangulo(double base, double altura) {
        super(base, altura);
        //this.valor = valor;
    }

    // Polimorfismo
    // Sobre escritura
    public double area() {
        return (this.base * this.altura) / 2.0;
    }

}

public class Herencia {
    public static void main(String[] args) {
        Rectangulo rect = new Rectangulo(5,6);
        System.out.println(rect.area());

        Triangulo tri = new Triangulo(5,6);
        System.out.println(tri.area());
    }
}