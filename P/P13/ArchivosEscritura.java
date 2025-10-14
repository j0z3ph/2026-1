import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class ArchivosEscritura {
    public static void main(String[] args) throws IOException {
        OutputStream archi = new FileOutputStream("archivo.txt");
        
        archi.write(40);
        archi.close();
    }
}
