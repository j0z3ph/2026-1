import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ArchivosRaros {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("archivo.txt"));

        while(fin.ready())
        System.out.println(fin.readLine());

        fin.close();
    }
}
