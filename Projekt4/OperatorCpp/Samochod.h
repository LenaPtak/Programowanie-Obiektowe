#include <iostream>
#include <memory>
using namespace std;

class Samochod
{
public:
    float pojemnosc_baku;
    float poziom_paliwa;
    unsigned int liczba_kilometrow;
    string model;

public:
    //Dodatkowe przeciązenie dla operatora ++
    float operator ++ (){
        return poziom_paliwa+1;
    }


    //Dodatkowe przeciązenie dla operatora ,
    bool operator , (const Samochod &samochod){
        return this->poziom_paliwa > samochod.pojemnosc_baku;
    }


    //Dodatkowe przeciązenie dla operatora |=
    bool operator |= (const Samochod &samochod){
        return this->poziom_paliwa || samochod.pojemnosc_baku;
    }


    //Dodatkowe przeciązenie dla operatora <<
    //Użyliśmy zaprzyjaźnienia funckji ostream z klasą Samochod, ponieważ z lewej strony operatora << ustawiamy zmienną typu ostream 
    //(i dzięki zaprzyjaźnieniu możemy taki typ ustawić), a z prawej strony wartości, które chcemy wysłać do streamu czyli samochod.model i samochod.poziom_paliwa. 
    friend ostream & operator << (ostream &os, const Samochod &samochod){
        os << samochod.model << " " << samochod.poziom_paliwa <<"\n";
        return os;
    }


    //Dodatkowe przeciązenie dla operatora <
    bool operator < (const Samochod &samochod) const{
        cout << endl << "Operator < jest przeciążony. " << this->model << " " << samochod.model << endl;
        return this->model < samochod.model;
    }

    //Dodatkowe przeciązenie dla operatora bool()
    operator bool() const {
        if ( (model == "") || (pojemnosc_baku <= 0.0) ) return false;
        else return true;
    }

    //Dodatkowe przeciązenie dla operatora !
    bool operator ! () const {
        if ( (model == "") || (pojemnosc_baku <= 0.0) ) return false;
        else return true;
    }


    float odczytaj_pojemnosc_baku(void);
    void dodaj_paliwo(float wartosc);       //Funkcja, w której możemy zmieniac stan paliwa.
    void dodaj_km(int wartosc);             //Funkcja, w której możemy zwiększyć licznik kilometrów.
    void wyswietl_dane();                   //Funckja wyświetla dane o wywolanym obiekcie.

    Samochod(float pojemnosc, string mod);  //Konstruktor z argumentami.
    Samochod();                             //Konstruktor domyślny.
    ~Samochod();                            //Destruktor.
};
