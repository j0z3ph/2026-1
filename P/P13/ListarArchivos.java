import java.io.File;
import java.io.FileFilter;
import java.time.LocalDateTime;
import java.util.Date;

public class ListarArchivos {
    private static String filtro;

    public static void main(String[] args) {
        filtro = "*";
        if (args.length > 0) {
            filtro = args[0];
        }

        File carpeta = new File(".");

        FileFilter mi_filtro = new FileFilter() {

            @Override
            public boolean accept(File pathname) {
                if (filtro.equals("*"))
                    return true;
                if (pathname.isFile()) {
                    if (pathname.getName().endsWith(filtro))
                        return true;
                    else
                        return false;
                } else {
                    return false;
                }
            }

        };
        File[] lista = carpeta.listFiles(mi_filtro);

        for (File archivo : lista) {
            // if(archivo.isDirectory())
            if (archivo.isDirectory())
                System.out.print("d");
            else
                System.out.print("-");

            if (archivo.canRead())
                System.out.print("r");
            else
                System.out.print("-");
            if (archivo.canWrite())
                System.out.print("w");
            else
                System.out.print("-");
            if (archivo.canExecute())
                System.out.print("x");
            else
                System.out.print("-");

            System.out.print("\t");

            System.out.print(archivo.length());
            System.out.print("\t");

            Date dt = new Date(archivo.lastModified());
            System.out.print( dt.toString());
            System.out.print("\t");

            System.out.println(archivo.getName());

            

            //archivo.setExecutable(true);
            

        }

    }
}
