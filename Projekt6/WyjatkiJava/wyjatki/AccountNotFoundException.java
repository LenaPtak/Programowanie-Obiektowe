public class AccountNotFoundException extends Exception {
    private int number;

    AccountNotFoundException(){};
    AccountNotFoundException(String errorMsg, int num){
        super(errorMsg);
        number = num;
    }

    int getNumber(){
        return this.number;
    }
}
