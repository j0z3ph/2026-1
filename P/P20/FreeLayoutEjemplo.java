import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

public class FreeLayoutEjemplo {
    
    public static void main(String[] args) {
        JFrame ventana = new JFrame("Mi diseño libre");
        ventana.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ventana.setSize(300, 300);

        ventana.setLayout(null);

        JTextField entrada = new JTextField();
        entrada.setLocation(50, 50);
        entrada.setSize(200, 20);
        ventana.add(entrada);

        JButton btn = new JButton("Aceptar");
        btn.setLocation(100, 100);
        btn.setSize(100, 50);
        ventana.add(btn);

        // Dandole funcionalidad a nuestro boton
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String nombre = entrada.getText();
                JOptionPane.showMessageDialog(null, "Saludos " + nombre, "Bienvenido", JOptionPane.ERROR_MESSAGE);
            }
        });

        ventana.setVisible(true);
    }
}
