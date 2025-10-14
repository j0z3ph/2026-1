import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class ArchivosWriter {
    public static void main(String[] args) throws IOException {
        Writer archi = new FileWriter("archivo.txt");
        
        archi.write("Holi Canoli \n :D");
        
        archi.close();
    }
}
