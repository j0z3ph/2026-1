public class ExcepcionNoVerificada {
    public static void main(String[] args) {
        int[] arreglo = { 1, 2, 3, 4, 5 };
        try {
            for (int i = 0; i <= 5; i++) {
                System.out.print(arreglo[i] + " ");
            }
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println();
        } catch (Exception e) {
            System.out.println(e.getLocalizedMessage());
        }

    }
}
