class Clase {
    public int atributo;

    public void metodo() {
        int variable;

        {
            int a;
        }
        a = 0;
    }

    
}

public class Principal {
    // Atributos
    private int valor;
    public static void main(String[] args) {
        Clase c = new Clase();
        Clase b = new Clase();
        c.atributo = 10;
        b.atributo = 10;
        

    }

}