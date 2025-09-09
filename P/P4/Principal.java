import java.util.Scanner;

public class Principal {
    public static void main(String[] args) {
        String str;
        Scanner scan = new Scanner(System.in);
        System.out.print("Usuario, ingrese una cadena: ");
        str = scan.nextLine();
        for (int i = str.length() - 1; i >= 0; i--) {
            System.out.print(str.charAt(i));
        }

        scan.close();
    }
}
