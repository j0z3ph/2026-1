import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class Ventanita {

    public static void main(String[] args) {
        JFrame ventana = new JFrame();
        JLabel etiqueta = new JLabel();
        JButton btn1 = new JButton("Boton 1");
        JButton btn2 = new JButton("Boton 2");

        etiqueta.setText("null");
        etiqueta.setHorizontalAlignment(JLabel.CENTER);

        ventana.setLayout(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();
        
        
        c.gridy = 0;
        c.gridx = 0;
        c.gridwidth = 2;
        ventana.add(etiqueta, c);

        c.gridy = 1;
        c.gridx = 0;
        c.gridwidth = 1;
        ventana.add(btn1, c);

        c.gridy = 1;
        c.gridx = 1;
        c.gridwidth = 1;
        ventana.add(btn2, c);


        ventana.setTitle("Una Ventanita");
        ventana.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        ventana.setSize(250, 500);
        ventana.setVisible(true);
    }
}