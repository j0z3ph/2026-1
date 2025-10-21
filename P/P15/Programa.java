public class Programa {
    public static void main(String[] args) {
        Persona p = new Persona();

        p.setNombre("Luis");
        try {
            p.setEdad(-100);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}