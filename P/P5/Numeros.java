import java.util.Scanner;

public class Numeros {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int numero;
        int suma = 0;
        System.out.print("Usuario, ingresa un numero: ");
        numero = scan.nextInt();

        for(;numero != 0;) {
            suma += (numero % 10);
            numero /= 10;
        }

        System.out.println("La suma es " + suma);

        scan.close();
    }
}
