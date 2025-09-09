import java.io.Console;

public class Prueba {
    public static void main(String[] args) {
        Console consola = System.console();
        System.out.println("Ingrese su contraseña: ");
        char[] contra = consola.readPassword();
        System.out.println(contra);

        consola.readLine();
    }
}
