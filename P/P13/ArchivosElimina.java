import java.io.File;

public class ArchivosElimina {
    public static void main(String[] args) {
        File archi = new File("archivo.txt");

        archi.delete();
    }
}
