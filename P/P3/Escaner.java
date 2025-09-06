import java.util.Scanner;

public class Escaner {

    public static void main(String[] args) {
        int edad;

        System.out.print("Ingresa tu edad: ");

        Scanner s = new Scanner(System.in);
        edad = s.nextInt();
        s.close();

        System.out.println("Naciste en " + (2025 - edad));
    }
}
