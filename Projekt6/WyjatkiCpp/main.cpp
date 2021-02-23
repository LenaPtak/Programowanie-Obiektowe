#include <iostream>
#include <string>
#include <vector>
using namespace std;

//W języku Java nieuwzględnienie w kodzie możliwości wystąpienia wyjątku jest błędem. 
//Każda funkcja musi tam mieć albo zapewnioną obsługę wszystkich wyjątków, albo musi listować jakie wyjątki może sama wyrzucać. 
//W języku C++ każda funkcja należy do jednej z dwóch kategorii: nie rzuca wyjątków, lub potencjalnie rzuca wyjątki. 


class StackException: public exception{
public:
    StackException(){}

    virtual const char* what() const noexcept override
    {
        return "Bledna operacja na stosie! Stos jest pusty.";
    }
};

//=========================================================================

class StackFullException: public StackException{
    int element=0;
    int maxStackSize=0;
    string message;

public:
    StackFullException(){}

    StackFullException(string p, int e,int s){
        message = p;
        element = e;
        maxStackSize = s;
    }


    virtual const char* what() const noexcept override{
        return "StackFullException błąd!";
    }
};

//===========================================================================

class Stack
{
private:
    int maxStackSize;
    vector<int> dfs;
    int top;

public:
    void push(int newItem);
    int pop();

    //Jeśli jakakolwiek funkcja wywołana między tą, która zgłasza wyjątek, a taka, 
    //która obsługuje wyjątek, jest określona jako noexcept , noexcept(true), 
    //program zostanie przerwany, gdy funkcja noexcept propaguje wyjątek.
    Stack(void);
    Stack(int max);
    ~Stack();
};

//=========================================================================

void Stack::push(int newItem)
    {
        if (dfs.size() < maxStackSize)
            dfs.push_back(newItem);
        else
        {
            throw StackFullException("Stos nie pomieści więcej elemntów!\n", 3, 10);
        }
    }


int Stack::pop()
    {
        if (dfs.size()>0)
        {
            int& ostatni = dfs.back();
            dfs.pop_back();
            return ostatni;
        }
        else
        {
            throw StackException();
        }
    }


Stack::Stack(void)
    :
    maxStackSize(0),
    dfs(0),
    top(0)
    {
    maxStackSize = 0;
    top = 0;
    }


Stack::Stack(int max)    
    :
    maxStackSize(0),
    dfs(0),
    top(0)
    {
    maxStackSize = max;
    }

Stack::~Stack(){}

//=========================================================================

//Obie funkcje zwracają błąd.
void foo(Stack &s){
    try{
        for (int i=0; i<=11; i++)
        {
            s.push(i);
        }
    }
    catch(StackFullException e){
        cout << e.what() << endl;
    }
}

void bar(Stack &s){
    try{
        for (int i=0; i<=11; i++)
        {
            s.push(i);
        }
    }
    catch(StackFullException &e)
    {
        cout << e.what() << endl;
    }
}


//=========================================================================


class StackEmptyException: public StackException{
private:
    string message;
public:
    StackEmptyException(){}
    StackEmptyException(string p){}
    virtual const char* what() const noexcept override{
        return "unia";
    }
};


//=========================================================================


int main()
{

    Stack stos1(10);
    Stack stos2(10);
    Stack stos3(10);
    Stack stos4(2);


    //Wyrzuci wyjątek, kiedy stos będzie pełny.
    // try{
    //     for (int i=0; i<=11; i++)
    //     {
    //         stos1.push(i);
    //     }
    // } catch(length_error &exp){
    //     printf(exp.what());
    // }

    // foo(stos2);
    // bar(stos3);


    try{
        //implementacja interakcji z użytkownikiem
        cout << endl << "Proszę wpisać:" << endl;
        cout << "   -dodaj              jeżeli chcesz dodać element do stosu," << endl;
        cout << "   -zdejmij               jeżeli chcesz zdjac ostatni element ze stosu," << endl;
        cout << "   -wyjscie            jeżeli chcesz wyjść." << endl << endl;

        string klucz;
        while (cin >> klucz)
        {
        if (klucz == "dodaj"){
            int liczba;
            cout << "Jaką liczbę chcesz dodać na stos?" << endl;
            cin >> liczba;
            stos4.push(liczba);
            cout << liczba << " została dodana" << endl;
        }
        else if (klucz == "zdejmij"){
            stos4.pop();
        }
        else if (klucz == "wyjdz"){
            break;
            }
        else{
            cout << endl << "Proszę wpisać:" << endl;
            cout << "   -dodaj              jeżeli chcesz dodać element do stosu," << endl;
            cout << "   -zdejmij               jeżeli chcesz zdjac element ze stosu," << endl;
            cout << "   -wyjscie            jeżeli chcesz wyjść." << endl << endl;
            }
        }
    } catch(StackException &e){
        printf(e.what());

    } catch(exception &e){
        printf(e.what());

    } catch(...){
        printf("Błąd operacji na stosie! Spróbuj jeszcze raz.");
    }


    return 0;
}