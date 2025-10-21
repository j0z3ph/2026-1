import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class ExcepcionVerificada {
    
    public static void main(String[] args) {
        File archi = new File("archivo.txt");
        FileReader fr;
        try {
            fr = new FileReader(archi);

            fr.close();
        } catch (IOException | ArrayIndexOutOfBoundsException e) {
            try {
                archi.createNewFile();
                fr = new FileReader(archi);
            } catch (IOException ex) {
                System.out.println("Upsss, lo intente, pero no pude ☹️");
            }
            //System.out.println(e.getMessage());
            //System.out.println("Upsss, ocurrio un error");
        }

        

        
    }
}
