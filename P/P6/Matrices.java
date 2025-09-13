public class Matrices {
    public static void main(String[] args) {
        int[][] matrix = new int[3][3];
        int cont = 1;

        for (int fila = 0; fila < matrix.length; fila++) {
            for (int columna = 0; columna < matrix[fila].length; columna++) {
                matrix[fila][columna] = cont++;
            }
        }

        for (int[] fila : matrix) {
            for (int valor : fila) {
                System.out.print(valor + " ");
            }
            System.out.println();
        }
    }
}
