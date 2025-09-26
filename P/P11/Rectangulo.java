public class Rectangulo extends Figura {
    
    public Rectangulo(double base, double altura) {
        super(base, altura);
    }

    @Override
    public double area() {
        return this.base * this.altura;
    }
}
