public class Persona {

    protected String nombre;

    public Persona(String nombre) {
        this.nombre = nombre;
    }
    
    public final String habla() {
        return "Hola a todes";
    }
}
