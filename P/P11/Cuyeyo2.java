interface Imprimible {
    public void setValor(int valor);
    public String to_String();
    default public void setColor(int color) {
        System.out.println("Color");
    }
}

class Carta implements Imprimible {

    @Override
    public void setValor(int valor) {
        System.out.println("Nada");
    }

    @Override
    public String to_String() {
        return "Nada";   
    }


}


public class Cuyeyo2 {
    public static void main(String[] args) {
        
    }
}
