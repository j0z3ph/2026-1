import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class ManejoExcepciones {
    public static void main(String[] args) {
        Persona p = new Persona();
        p.setNombre("Emi");
        File archi = new File("archivo.txt");
        
        try(FileReader fr = new FileReader(archi)) {

        } catch (Exception ex) {
            
        }

        try {
            p.setEdad(-19);
            
        } catch (MenorDeEdadException e) {
            e.printStackTrace();
        } //catch (FileNotFoundException e) {
        //    e.printStackTrace();
        /* } finally {
            if(fr != null)
                try {
                    fr.close();
                } catch (IOException e) {
                    // NADA
                }
        }*/
    }
}