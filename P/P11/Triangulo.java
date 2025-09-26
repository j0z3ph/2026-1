public class Triangulo extends Figura {
    
    public Triangulo(double base, double altura) {
        super(base, altura);
    }

    @Override
    public double area() {
        return (this.base * this.altura) / 2.0;
    }
}
