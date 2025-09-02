public class Principal {
    public static void main(String[] args) {
        System.out.println("Hola Mundo");

        System.out.println(suma(5,6));
    }

    /**
     * Suma dos numeros enteros
     * @param a El primer numero
     * @param b El segundo numero
     * @return La suma
     */
    public static int suma(int a, int b) {
        return a + b;
    }
}