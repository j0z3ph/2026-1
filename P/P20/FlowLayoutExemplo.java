import javax.swing.JButton;
import javax.swing.JFrame;
import java.awt.FlowLayout;

public class FlowLayoutExemplo {
    public static void main(String[] args) {
        JFrame ventana = new JFrame("Flow Layout Ejemplo");
        ventana.setSize(300, 300);
        ventana.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Ponemos el flowlayout
        ventana.setLayout(new FlowLayout());

        // Creamos los botones
        JButton btn1 = new JButton("Clickeame!!");
        JButton btn2 = new JButton("No me clickees :c");

        // Agregamos a ventana
        ventana.add(btn1);
        ventana.add(btn2);

        ventana.setVisible(true);
    }
}
