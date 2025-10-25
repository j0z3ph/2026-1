import java.awt.Point;

import javax.swing.JButton;
import javax.swing.JFrame;

public class MiVentana {
    
    public static void main(String[] args) {
        JFrame ventana = new JFrame();
        JButton boton = new JButton();

        boton.setText("Pushame 😏");
        boton.setSize(100, 50);
        boton.setLocation(new Point(100,100));

        ventana.setLayout(null);
        ventana.add(boton);
        ventana.setSize(500, 550);
        ventana.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ventana.setTitle("Mi Primer Ventana 😱");
        ventana.setVisible(true);
    }
}
