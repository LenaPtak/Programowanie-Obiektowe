package recycling;

import java.util.TreeMap;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Scanner;

public class Wezel {
    private static final Object True = null;
    int numerWezla;
    ArrayList<Wezel> polaczenia;
    // HashMap<int,  Wezel> polaczeniaHash;
    //TreeMap polaczeniaTree;
    @Deprecated
    @Override



    //////////////////////////////////////////////////
    protected void finalize() throws Throwable {
        System.out.println("Finalizowanie obiektu");
        super.finalize();
    }

    public Wezel(int numerWezla){   
        this.numerWezla = numerWezla;
        polaczenia = new ArrayList<>();
    }

    //////////////////////////////////////////////////
    public void Group(int howMany){
        HashMap<String, Integer> namesHash = new HashMap<String, Integer>();

        namesHash.put("Anna", 34);
        namesHash.put("Brook", 21);
        namesHash.put("Jakub", 19);
        namesHash.put("Ola", 32);
        System.out.println(namesHash);


        TreeMap<String, Integer> namesTree = new TreeMap<String, Integer>();

        for (int i=0; i <= howMany; i++){
            namesTree.put("Kate", 20);
            namesTree.put("Michael", 18);
            namesTree.put("John", 34);
            namesTree.put("Ciri", 34);
        }
        namesTree.remove("John");
        namesHash.remove("Ola");
    } 

    //////////////////////////////////////////////////
    public void dodajPolaczenie(Wezel w){
        this.polaczenia.add(w);
    }

    //////////////////////////////////////////////////
    public static void main(String[]args)
    {
        Scanner s = new Scanner (System.in);
        for(int i=0; i <= 10000000; i++){
            Wezel w = new Wezel(i);
            //Wezel w1 = new Wezel();
            // Wezel w2 = new Wezel();
            // w1.dodajPolaczenie(w2);
            // w2.dodajPolaczenie(w1);
            w.Group(3);

        }
        s.nextLine();
        s.close();
    }

    //Język Java wykorzystuje mechanizm GarbageCollector - automatyczne zwalnianie pamięci ze sterty. 
    //Zmienne w1 i w2 są niszczone po wyjściu z iteracji (są lokalne) 
    //i po ich zniszczeniu nie ma żadnych jawnych referencji do utworzonych obiektów i dlatego obiekty są niszczone.

    //Tradycyjna lista nie była najlepszym wyborem, ponieważ ArrayList<>() jest prostsza w obsłudze i o wiele bardziej funkcjonalna.
}