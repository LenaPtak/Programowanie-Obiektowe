import java.util.ArrayList;

public class Bank implements SearchAccounts, SearchCustomers {
    ArrayList<Customer> customers = new ArrayList<Customer>();
    ArrayList<Account> accounts = new ArrayList<Account>();

    @Override
    public Customer findByName(String name, String surname) throws CustomerNotFoundException{
        for(int i = 0; i < customers.size(); i++) {
            if ((customers.get(i).getName() + customers.get(i).getSurname()).equals(name + surname))
                return customers.get(i);
        }
        throw new CustomerNotFoundException("Customer was not found.", name, surname);
    }

    @Override
    public Account findByNumber(int num) throws AccountNotFoundException{
        for(int i = 0; i < accounts.size(); i++) {
            if (accounts.get(i).getNumber() == num)
                return accounts.get(i);
        }
        throw new AccountNotFoundException("Account not found.", num);
    }

    @Override
    public ArrayList<Account> findAllCustomerAccounts(Customer cust) throws AccountNotFoundException{
        ArrayList<Account> konta = new ArrayList<Account>();
        for(int i = 0; i < accounts.size(); i++) {
            if (accounts.get(i).getCustomer() == cust)
                konta.add(accounts.get(i));
        }
        if (konta.isEmpty())
            throw new AccountNotFoundException("None account was found", 0);
        else
            return konta;

    }

    public void addCustomer(Customer customer){ this.customers.add(customer); }
    public void addAccount(Account account){ this.accounts.add(account); }
}
//Interfejs wskazuje co klasa musi robić, ale nie wskazuje w jaki sposob ma te zadania wykonać, określa sie w nim metody które klasa musi zaimplementować.
//Różne klasy moga implementować te same interfejsy, pomagają one zgrupować powiązane ze sobą metody w jednym miejscu.