#include <iostream>
#include <time.h>
#include <ctime>
#include <unistd.h>
#include "Student.h"
#include "Osoba.h"
#include "Pracownik.h"
#include "Adres.h"

using namespace std;



//Ustawienie imienia i nazwiska.
void Osoba::ustaw_imie_naz(string nowe_imie){          
    *imie_nazwisko = nowe_imie;}


//Odczytanie imienia i nazwiska.
string Osoba::odczytaj_imie_naz(void){      
    return *imie_nazwisko;}


//Ustawienie daty urodzenia ze sprawdzeniem poprawności przekazanej daty.
void Osoba::ustaw_date(time_t nowa_data){              
    if (difftime(nowa_data, time(0)/(60*24*365)) > 120) //Difftime zwraca czas w sekundach, a my chcemy w latach.
        *data_urodzenia = nowa_data;}
    

//Odczytanie daty urodzenia.
time_t Osoba::odczytaj_date(void){           
    return *data_urodzenia;}


//Ustawienie miejsca zamieszkania ze sprawdzeniem poprawności przekazanych daych adresowych.
void Osoba::ustaw_miejsce(string ulica, int nr_domu, string miejscowosc){          
    if (ulica.length() > 0 && nr_domu > 0 && miejscowosc.length() > 0 ){
        fadres->ulica = ulica;
        fadres->nr_domu = nr_domu;
        fadres->miejscowosc = miejscowosc;}}


//Odczytanie miejsca zamieszkania.
Adres Osoba::odczytaj_miejsce(void){        
    return *fadres;}


//Metoda o nazwie przedstaw, której zadaniem jest wyświetlenie pełnego opisu osoby.
void Osoba::przedstaw(void){               
    cout << "Imię i nazwisko: " << *imie_nazwisko << endl;

    char buffer[32];                            
    tm * ptm = localtime(data_urodzenia);
    strftime(buffer, 32, "%d-%m-%Y", ptm);
    cout << "Data urodzenia: " << buffer << endl;

    cout << "Ulica: " << fadres->ulica << endl;
    cout << "Nr domu: " << fadres->nr_domu << endl;
    cout << "Miejscowość: " << fadres->miejscowosc << endl;}


//Konwersja time_t2string.
time_t Osoba::String2Time(string data){
    int dd, mm, yy;
    struct tm when = {0};

    sscanf_s(data.c_str(), "%d-%d-%d", &dd, &mm, &yy);

    when.tm_mday = dd;
    when.tm_mon = mm-1;
    when.tm_year = yy-1900;

    return mktime(&when);
}


//------KONSTRUKTORY I DESTRUKTOR----------------------------------------------------------------------------
//Wszystkie konstruktowy działają poprawnie oraz poprawnie zwalniają pamięć.


//Konstruktor domyślny.
Osoba::Osoba(void)    
    :
    imie_nazwisko(nullptr),
    data_urodzenia(nullptr),
    fadres(nullptr)
    {}            


//Konstruktor z parametrami.
Osoba::Osoba(char* imie_nazwisko, char* data_urodzenia, char* ulica, int nr_domu, char* miejscowosc)
    :
    imie_nazwisko(nullptr),
    data_urodzenia(nullptr),
    fadres(nullptr)
{
    this->imie_nazwisko = new string;
    if (imie_nazwisko!=nullptr)
        *this->imie_nazwisko = imie_nazwisko;
    this->data_urodzenia = new time_t;
    if (data_urodzenia!=nullptr)
        *this->data_urodzenia = String2Time(data_urodzenia);
    fadres = new Adres;
    if (ulica!=nullptr)
        fadres->ulica = ulica;
    fadres->nr_domu = nr_domu;
    if (miejscowosc!=nullptr)
        fadres->miejscowosc = miejscowosc;
}


//Konstruktor kopiujący.
Osoba::Osoba(const Osoba& kopia)
    :
    imie_nazwisko(nullptr),
    data_urodzenia(nullptr),
    fadres(nullptr)
{
    this->imie_nazwisko = new string(*(kopia.imie_nazwisko));
    this->data_urodzenia = new time_t(*(kopia.data_urodzenia));
    fadres = new Adres(*(kopia.fadres));
} 


//konstruktor przenoszący.
Osoba::Osoba(Osoba&& other)
    :
    imie_nazwisko(nullptr),
    data_urodzenia(nullptr),
    fadres(nullptr)
{
    imie_nazwisko = other.imie_nazwisko;
    data_urodzenia = other.data_urodzenia;
    fadres = other.fadres;

    other.imie_nazwisko = nullptr;
    other.data_urodzenia = nullptr;
    other.fadres = nullptr;
}                                               


//Konstruktor konwertujacy.
Osoba::Osoba(int parametr)
    :
    imie_nazwisko(nullptr),
    data_urodzenia(nullptr),
    fadres(nullptr)
    {}


////Wirtualny destruktor.
Osoba::~Osoba(){
    delete imie_nazwisko;
    delete data_urodzenia;
    delete fadres;
}