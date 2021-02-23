public interface SearchCustomers {
    Customer findByName(String name, String surname) throws CustomerNotFoundException;
}
