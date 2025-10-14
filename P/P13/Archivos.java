import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class Archivos {

    public static void main(String[] args) throws IOException {
        File archi = new File("archivo.txt");
        if(!archi.exists()) {
            System.out.println("El archivo no existe :C");
            System.exit(1);
        }

        FileInputStream fin = new FileInputStream(archi);

        while(fin.available() > 0)
            System.out.print((char)fin.read());

        fin.close();
    }
}
