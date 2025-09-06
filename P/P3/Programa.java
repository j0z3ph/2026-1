import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Programa {
    public static void main(String[] args) throws IOException {
        int edad;
        System.out.print("Usuario, ingresa tu edad: ");

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String entrada = br.readLine();
        edad = Integer.parseInt(entrada);

        System.out.println("Naciste en " + (2025 - edad));
    }
}
