import java.util.Scanner;

public class ParImpar {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int numero;
        
        System.out.print("Dame un numero o te pico >:C ");
        numero = scan.nextInt();

        System.out.println("El numero es " + ((numero & 1) == 0 ? "PAR" : "IMPAR"));

        scan.close();
    }
}
