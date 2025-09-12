public class Arreglo {
    
    public static void main(String[] args) {
        int[] arrg = new int[10];

        for (int i = 0; i < arrg.length; i++) {
            arrg[i] = i+1;
        }

        for (int i : arrg) {
            System.out.print(i + " ");
        }

        System.out.println(arrg[10]);
    }
}
