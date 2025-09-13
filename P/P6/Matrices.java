public class Matrices {

    public static void imprime(int[][] matrix){
        for (int[] fila : matrix) {
            for (int valor : fila) {
                System.out.print(valor + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] matrix = new int[3][3];
        int cont = 1;
        int[][] traspuesta = new int[3][3];
        int determinante;

        for (int fila = 0; fila < matrix.length; fila++) {
            for (int columna = 0; columna < matrix[fila].length; columna++) {
                matrix[fila][columna] = cont++;
            }
        }

        imprime(matrix);

        // Traspuesta
        for (int fila = 0; fila < matrix.length; fila++) {
            for (int columna = 0; columna < matrix[fila].length; columna++) {
                traspuesta[columna][fila] = matrix[fila][columna];
            }
        }

        imprime(traspuesta);

        // determinante

        determinante = matrix[0][0]*matrix[1][1]*matrix[2][2] +
                    matrix[1][0]*matrix[2][1]*matrix[0][2] +
                    matrix[2][0]*matrix[0][1]*matrix[1][2] -
                    matrix[2][0]*matrix[1][1]*matrix[0][2] -
                    matrix[0][0]*matrix[2][1]*matrix[1][2] -
                    matrix[1][0]*matrix[0][1]*matrix[2][2];

            System.out.println(determinante);
    }
}
