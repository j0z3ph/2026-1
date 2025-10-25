import javax.swing.JOptionPane;

public class Ventana {

    public static void main(String[] args) {
        JOptionPane.showMessageDialog(null, "Hola Mundo 😸", "Titulo", JOptionPane.WARNING_MESSAGE);

        JOptionPane.showConfirmDialog(null, "Estas seguro?", "Pregunta", JOptionPane.YES_NO_CANCEL_OPTION);
    }
}
