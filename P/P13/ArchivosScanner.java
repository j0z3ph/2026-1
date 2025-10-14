import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ArchivosScanner {
    public static void main(String[] args) throws FileNotFoundException {
        File archi = new File("archivo.txt");
        Scanner fin = new Scanner(archi);
        /*while(fin.hasNextLine()) {
            System.out.println(fin.nextLine());
            
        }*/

        System.out.println(fin.nextLine());
        System.out.println(fin.nextLine());
        int var = fin.nextInt();
        var++;
        System.out.println(var);
        System.out.println(fin.nextBoolean());

        fin.close();
    }
}
