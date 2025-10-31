import javax.swing.JButton;
import javax.swing.JFrame;
import java.awt.BorderLayout;

public class BorderLayoutEjemplo {
    public static void main(String[] args) {
        JFrame ventana = new JFrame();

        JButton btn1 = new JButton();
        btn1.setText("Norte");
        JButton btn2 = new JButton();
        btn2.setText("Sur");
        JButton btn3 = new JButton();
        btn3.setText("Este");
        JButton btn4 = new JButton();
        btn4.setText("Oeste");
        JButton btn5 = new JButton();
        btn5.setText("Centro");
        
        ventana.add(btn1, BorderLayout.NORTH);
        ventana.add(btn2, BorderLayout.SOUTH);
        ventana.add(btn3, BorderLayout.EAST);
        ventana.add(btn4, BorderLayout.WEST);
        ventana.add(btn5, BorderLayout.CENTER);

        ventana.setSize(250, 150);
        ventana.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ventana.setVisible(true);
        
    }
}
