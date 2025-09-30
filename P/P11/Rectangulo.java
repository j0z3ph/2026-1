public class Rectangulo extends Figura implements Interface {
    
    public Rectangulo(double base, double altura) {
        super(base, altura);
    }

    @Override
    public double area() {
        return this.base * this.altura;
    }

    @Override
    public void metodo() {

    }
}
