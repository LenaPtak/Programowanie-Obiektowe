public class Account
{
    private int accountNumber;
    private Customer owner;
    private double balance;
    private int password;
    private String login;
    public Account (){}

    public Account (int a, int n , Customer c , int p , String l)
    {
        this.accountNumber = a;
        this.balance = n;
        this.owner = c;
        this.password = p;
        this.login = l;
    }
    public void login (String l, int passwd) throws AccountLoginFailedException
    {
        if (l == this.login && passwd == this.password)
            System.out.println("Successfully logged in!!");
        else
            throw new AccountLoginFailedException("Wrong password or login!!", l, passwd);
    }
    public Customer getCustomer () { return this.owner; }
    public int getNumber () { return this.accountNumber; }
    public double getBalance () { return this.balance; }
    public double withdraw (double amount)
    {
        System.out.println("Wyplacaanie");
        this.balance -= amount;
        return this.balance;
    }
    public String getInfo() { return "accountNumber: " + this.accountNumber + " balance: " + this.balance + " owner: " + this.owner.getName() + " password: " + this.password + " login: " + this.login; }
}
