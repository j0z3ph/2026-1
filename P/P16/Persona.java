public class Persona {
    
    private String nombre;
    private int edad;
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    public void setEdad(int edad) throws MenorDeEdadException {
        if(edad < 18) {
            throw new MenorDeEdadException("Debes ser mayor de edad");
        } else 
        this.edad = edad;
    }
    public String getNombre() {
        return nombre;
    }
    public int getEdad() {
        return edad;
    }
}
