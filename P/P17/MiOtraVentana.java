import java.awt.Button;
import java.awt.Frame;

public class MiOtraVentana {
    
    public static void main(String[] args) {
        Frame ventana = new Frame();
        Button boton = new Button();

        boton.setLabel("Comeme 🤪");
        boton.setSize(100, 100);
        boton.setLocation(100, 100);

        ventana.setLayout(null);
        ventana.add(boton);

        ventana.setTitle("Holi Canoli 🍖");
        ventana.setSize(500, 550);

        ventana.setVisible(true);
    }
}
