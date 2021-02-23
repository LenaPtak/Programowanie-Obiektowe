import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Customer customer1 = new Customer("Nick", "Kind", "3878527503", "USA, Miami, Canadian Street 34");
        Customer customer2 = new Customer("Kate", "MCkenzie", "58741265895", "Poland, Wroclaw, ul. Kwiatowa 290");
        Account account1 = new Account(123, 1000000, customer1, 12390, "joshi");
        Account account2 = new Account(124, 26, customer1, 111, "jjj");
        Bank bank = new Bank();

        bank.addCustomer(customer1);
        bank.addCustomer(customer2);
        bank.addAccount(account1);
        bank.addAccount(account2);

        System.out.println("Testing account number " + 124 + "...");
        try{
            bank.findByNumber(122);
            System.out.println("Account found");
        }
        catch (Exception e){
            e.printStackTrace();
            //Metoda fillInStackTrace() zastepuje oryginalny slad stosu tym, z miejsca, w ktorym zostal wywolany, 
            //w konsekwencji za drugim wywolaniem printStackTrace() (i oczywiscie fillInStackTrace()) widzimy troche mniej informacji.
            e.fillInStackTrace(); 
            e.printStackTrace();
            //Tak, slady stosu sa takie same przy kolejnym wywolaniu printStackTrace().
        }

        System.out.println();
        System.out.println("Testing customer name Josh Nice...");
        try{
            bank.findByName("Nick", "Kind");
            System.out.println("Customer found");
        }
        catch (Exception e){
            e.printStackTrace();
        }

        System.out.println();
        System.out.println("Searching for all Nick Kind's accounts...");
        try{
            ArrayList<Account> lista = bank.findAllCustomerAccounts(customer1);
            for (int i = 0; i < lista.size(); i++)
                System.out.println(lista.get(i).getInfo());
        }
        catch (Exception e){
            e.printStackTrace();
        }

        System.out.println();
        System.out.println("Log in:");
        try{
            Scanner input = new Scanner(System.in);

//            System.out.println("Give a login: ");
//            String login = input.next();
//            System.out.println("Give a password: ");
//            int passwd = input.nextInt();
            String login = "nicki";
            int passwd = 12390;
            bank.findByNumber(123).login(login, passwd);
        }
        catch (Exception e){
            e.printStackTrace();
        }
    }
}
