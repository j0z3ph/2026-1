import java.time.LocalDate;

class Persona {

    // public static int atributo_de_clase;

    // public static void metodo() {
    // System.out.println("Soy estatico");
    // }

    // Atributos
    private String nombre;
    private String apellido1;
    private String apellido2;
    private LocalDate fnacimiento;
    private String curp;

    // Constructor por defecto
    Persona(String nombre, String apellido1,
            String apellido2, LocalDate fnacimiento, String curp) {
        this.nombre = nombre;
        this.apellido1 = apellido1;
        this.apellido2 = apellido2;
        this.curp = curp;
        this.fnacimiento = fnacimiento;
    }

    Persona(String nombre, String apellido1,
            String apellido2, String curp) {
        this.nombre = nombre;
        this.apellido1 = apellido1;
        this.apellido2 = apellido2;
        this.curp = curp;
        this.fnacimiento = null;
    }

    // Getters
    public String getNombre() {
        return nombre;
    }

    public String getApellido1() {
        return apellido1;
    }

    public String getApellido2() {
        return apellido2;
    }

    public String getCurp() {
        return curp;
    }

    public LocalDate getFnacimiento() {
        return fnacimiento;
    }

    // Setters
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setApellido1(String apellido1) {
        this.apellido1 = apellido1;
    }

    public void setApellido2(String appellido2) {
        this.apellido2 = appellido2;
    }

    public void setCurp(String curp) {
        this.curp = curp;
    }

    public void setFnacimiento(LocalDate fnacimiento) {
        this.fnacimiento = fnacimiento;
    }

}


class Alumno extends Persona{
    
    Alumno(){
        super(null, null, null, null);
    }

}

public class Programa {

    public static void main(String[] args) {
        {
            Persona p1 = new Persona("Evelin", "Hernandez", "Gomez", LocalDate.of(2006, 11, 16), "KJDKAJHJDKAJHJKDHKJA");

            p1.setApellido2("null");

            System.out.println(p1.getNombre());

            Alumno a = new Alumno();
            a.setApellido2("");
        }


        
    }
}
