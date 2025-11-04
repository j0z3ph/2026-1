import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;

public class BoxLayoutEjemplo {
    
    public static void main(String[] args) {
        JFrame ventana = new JFrame("BoxLayout");

        JButton btn1 = new JButton("Boton 1");
        JButton btn2 = new JButton("Boton 2");
        JButton btn3 = new JButton("Boton 3");
        JButton btn4 = new JButton("Boton 4");
        
        ventana.setLayout(new BoxLayout(ventana.getContentPane(), BoxLayout.X_AXIS));

        ventana.add(btn1);
        ventana.add(btn2);
        ventana.add(btn3);
        ventana.add(btn4);

        ventana.setSize(500, 500);
        ventana.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ventana.setVisible(true);
    }
}
