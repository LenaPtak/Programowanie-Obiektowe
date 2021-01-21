#ifndef Osoba_h
#define Osoba_h
#include <iostream>
#include "Adres.h"
using namespace std;

class Osoba
{
public:
    string* imie_nazwisko;
    time_t* data_urodzenia;
    Adres* fadres;

public:
    void ustaw_imie_naz(string nowe_imie);                              //Ustawienie imienia i nazwiska.
    string odczytaj_imie_naz(void);                                     //Odczytanie imienia i nazwiska.
    void ustaw_date(time_t nowa_data);                                  //Ustawienie daty urodzenia ze sprawdzeniem poprawności przekazanej daty.
    time_t odczytaj_date(void);                                         //Odczytanie daty urodzenia.
    void ustaw_miejsce(string ulica, int nr_domu, string miejscowosc);  //Ustawienie miejsca zamieszkania ze sprawdzeniem poprawności przekazanych daych adresowych.
    Adres odczytaj_miejsce(void);                                       //Odczytanie miejsca zamieszkania.

    //Specyfikator virtual pozwala nam na wykonanie funkcji przedstaw() nie tylko z właściwościami klasy Osoba, ale także klasy Student i Pracownik.    
    //Jeżeli w klasie jest przynajmniej jedna metoda czysto wirtualna, to jest to klasa abstrakcyjna.
    virtual void przedstaw(void);                                       //Metoda o nazwie przedstaw, której zadaniem jest wyświetlenie pełnego opisu osoby.
    

    //Dodatkowo:
    virtual void funkcja_abstrakcyjna(void) = 0;                        //Przykładowa funkcja abstrakcyjna.   
    time_t String2Time(string data);                                    //Konwersja typu string na typ time_t.

    Osoba& operator=(Osoba&& other){                                    //Operator przypisania przenoszenia w związku z konstruktorem przenoszącym.
        if (this != &other)
            {
                    delete imie_nazwisko;
                    delete data_urodzenia;
                    delete fadres;

                    imie_nazwisko = other.imie_nazwisko;
                    data_urodzenia = other.data_urodzenia;
                    fadres = other.fadres;

                    other.imie_nazwisko = nullptr;
                    other.data_urodzenia = nullptr;
                    other.fadres = nullptr;
            }
        return *this;
    }


    Osoba(void);                                                        //Konstruktor domyślny.
    Osoba(char* imie_nazwisko, char* data_urodzenia = nullptr, char* ulica = nullptr, int nr_domu = 0, char* miejscowosc = nullptr);
    Osoba(const Osoba& kopia);                                          //konstruktor kopiujący.
    Osoba(Osoba&& other);                                               //konstruktor przenoszący.
    Osoba(int parametr);                                                //Konstruktor konwertujący.
    //Niewirtualny destruktor może powodować wycieki pamięci i niezdefiniowane zachowanie programu, 
    //ponieważ będzie wywoływany ten, który odpowiada typowi wskaźnika, a nie ten, który odpowiada rzeczywistemu typowi obiektu.
    virtual ~Osoba();                                                   //Wirtualny destruktor.
};

#endif