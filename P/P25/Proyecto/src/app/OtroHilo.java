/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package app;

/**
 *
 * @author josel
 */
public class OtroHilo implements Runnable {

    private Ventana ventana;
    
    public OtroHilo(Ventana ventana) {
        this.ventana = ventana;
    }
    
    @Override
    public void run() {
        for(int i = 0; i <= 100; i++) {
            this.ventana.setValorBarrita(i);
            try {
                Thread.sleep(100);
            } catch (InterruptedException ex) {
                System.getLogger(Ventana.class.getName()).log(System.Logger.Level.ERROR, (String) null, ex);
            }
        }
    }
    
}
