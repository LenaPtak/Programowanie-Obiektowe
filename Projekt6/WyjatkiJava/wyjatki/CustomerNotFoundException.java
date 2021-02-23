public class CustomerNotFoundException extends Exception {
    private String name;
    private String surname;

    CustomerNotFoundException(){};
    CustomerNotFoundException(String errorMsg, String n, String s){
        super(errorMsg);
        name = n;
        surname = s;
    }
    String getName() {return this.name;}
    String getSurname() {return this.surname;}
}
