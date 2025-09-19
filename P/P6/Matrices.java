public class Matrices {

    public static void imprime(int[][] matrix) {
        for (int[] fila : matrix) {
            for (int valor : fila) {
                System.out.print(valor + " ");
            }
            System.out.println();
        }
    }

    public static void imprime(double[][] matrix) {
        for (double[] fila : matrix) {
            for (double valor : fila) {
                System.out.print(valor + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] matrix = new int[3][3];
        int[][] adjunta = new int[3][3];
        double[][] inversa = new double[3][3];
        int cont = 1;
        int[][] traspuesta = new int[3][3];
        int determinante;
        double factor;


        for (int fila = 0; fila < matrix.length; fila++) {
            for (int columna = 0; columna < matrix[fila].length; columna++) {
                matrix[fila][columna] = cont++;
            }
        }

        matrix[0][1] = 15;

        imprime(matrix);

        // determinante

        determinante = matrix[0][0] * matrix[1][1] * matrix[2][2] +
                matrix[1][0] * matrix[2][1] * matrix[0][2] +
                matrix[2][0] * matrix[0][1] * matrix[1][2] -
                matrix[2][0] * matrix[1][1] * matrix[0][2] -
                matrix[0][0] * matrix[2][1] * matrix[1][2] -
                matrix[1][0] * matrix[0][1] * matrix[2][2];

        if (determinante == 0) {
            System.out.println("La matriz no tiene inversa :'(");
            System.exit(1);
        }

        factor = 1.0 / (double)determinante;

        // Traspuesta
        for (int fila = 0; fila < matrix.length; fila++) {
            for (int columna = 0; columna < matrix[fila].length; columna++) {
                traspuesta[columna][fila] = matrix[fila][columna];
            }
        }

        // Adjunta
        adjunta[0][0] = (+1) * (traspuesta[1][1] * traspuesta[2][2] - traspuesta[2][1] * traspuesta[1][2]);
        adjunta[0][1] = (-1) * (traspuesta[1][0] * traspuesta[2][2] - traspuesta[2][0] * traspuesta[1][2]);
        adjunta[0][2] = (+1) * (traspuesta[1][0] * traspuesta[2][1] - traspuesta[2][0] * traspuesta[1][1]);
        adjunta[1][0] = (-1) * (traspuesta[0][1] * traspuesta[2][2] - traspuesta[2][1] * traspuesta[0][2]);
        adjunta[1][1] = (+1) * (traspuesta[0][0] * traspuesta[2][2] - traspuesta[2][0] * traspuesta[0][2]);
        adjunta[1][2] = (-1) * (traspuesta[0][0] * traspuesta[2][1] - traspuesta[2][0] * traspuesta[0][1]);
        adjunta[2][0] = (+1) * (traspuesta[0][1] * traspuesta[1][2] - traspuesta[1][1] * traspuesta[0][2]);
        adjunta[2][1] = (-1) * (traspuesta[0][0] * traspuesta[1][2] - traspuesta[1][0] * traspuesta[0][2]);
        adjunta[2][2] = (+1) * (traspuesta[0][0] * traspuesta[1][1] - traspuesta[1][0] * traspuesta[0][1]);

        
        // Inversa
        for (int f = 0; f < traspuesta.length; f++) {
            for (int c = 0; c < traspuesta[f].length; c++) {
                inversa[f][c] = factor * adjunta[f][c];
            }
        }

        // Imprimimos
        imprime(inversa);

    }
}
