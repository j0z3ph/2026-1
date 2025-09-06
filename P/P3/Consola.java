import java.io.Console;

public class Consola {

    public static void main(String[] args) {
        int edad;

        System.out.print("Edad >:| ");
        Console c = System.console();

        char[] pass = c.readPassword();
        edad = Integer.parseInt(new String(pass));

        System.out.println("Anio " + (2025-edad));
    }
}
