import java.util.ArrayList;

public interface SearchAccounts {
    Account findByNumber(int nmumber) throws AccountNotFoundException;
    ArrayList<Account> findAllCustomerAccounts(Customer cust) throws AccountNotFoundException;
}
