import java.util.Scanner;

public class Factorial {
    public static long factorial(long n) {
        if (n == 0)
            return 1;
        else {
            return n * factorial(n - 1);
        }
    }

    public static void main(String[] args) {
        long numero;
        long facto = 1;
        Scanner scan = new Scanner(System.in);

        System.out.print("Usuario, ingresa un numero: ");
        numero = scan.nextLong();

        for (long i = numero; i > 0; i--) {
            facto *= i;
        }

        System.out.println("El factorial de " + numero + " es " + factorial(numero) + ".");

        scan.close();
    }
}
