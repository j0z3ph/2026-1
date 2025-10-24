public class MenorDeEdadException extends RuntimeException {
    private String msg;
    MenorDeEdadException(String message){
        this.msg = message;
    }

    @Override
    public String toString() {
        return this.msg;
    }
}
