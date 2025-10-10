import paquete.Clase;
import paquete.Clase2;
import paquete.utils.Clase3;
import java.io.File;
import java.io.IOException;

public class Programa {

    public static void main(String[] args) throws IOException {
        Clase c = new Clase();
        System.out.println(c.habla());
        Clase2 c2 = new Clase2();
        System.out.println(c2.despidete());
        Clase3 c3 = new Clase3();
        System.out.println(c3.presentate());

        /// Creacion de archivitos
        File archi = new File("archivos/archivito.txt");

        if (!archi.exists()) {
            System.out.println("Upsss, el archivo no existe. Lo intentare crear ;D");
            if (!archi.createNewFile()) {
                System.out.println("Upsss, no se pudo T-T");
                System.exit(1);
            } else {
                System.out.println("Si pude :D");
            }
        }
    }

}
