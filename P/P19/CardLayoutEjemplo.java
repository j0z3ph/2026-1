import java.awt.CardLayout;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class CardLayoutEjemplo {
 
    public static void main(String[] args) {
        JFrame ventana = new JFrame("CardLayout");

        JButton btn3 = new JButton("Boton 1.1");
        JButton btn4 = new JButton("Boton 2.1");
        JButton btn1 = new JButton("Boton 1");
        JButton btn2 = new JButton("Boton 2");

        CardLayout tarjeta = new CardLayout(50, 50);
        Container contenedor = ventana.getContentPane();

        contenedor.setLayout(tarjeta);

        btn1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tarjeta.next(contenedor);
            }
        });

        btn2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tarjeta.next(contenedor);
            }
        });

        btn3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tarjeta.next(contenedor);
            }
        });

        btn4.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tarjeta.next(contenedor);
            }
        });

        contenedor.add("1", btn1);
        contenedor.add("2", btn2);
        contenedor.add("3", btn3);
        contenedor.add("4", btn4);

        
        ventana.setSize(500, 500);
        ventana.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ventana.setVisible(true);


        
        
    }
}
