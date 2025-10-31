import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;

public class GridLayoutEjemplo {
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
        JButton btn6 = new JButton();
        btn6.setText("Centro 2");
        
        ventana.add(btn1);
        ventana.add(btn2);
        ventana.add(btn3);
        ventana.add(btn4);
        ventana.add(btn5);
        ventana.add(btn6);

        ventana.setLayout(new GridLayout(3, 2));
        ventana.setSize(250, 150);
        ventana.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ventana.setVisible(true);
        
    }
    
}
