#include <iostream>
#include <stdio.h>
#include <time.h>
#include "RadaNadzorcza.h"
#include "Logger.h"
#include "Stopper.h"

using namespace std;

//Konstruktor domyślny.
Rada_Nadzorcza::Rada_Nadzorcza(void)
    //Rozpoczecie listy inicjalizacyjnej.
    : 
    f_ilosc_czlonkow(nullptr),
    uchwaly_liczba(nullptr), 
    uchwaly_lata(nullptr), 
    f_budzet_stan(nullptr), 
    f_data_nast(nullptr),
    f_data_ost(nullptr),
    f_prezes(nullptr),
    f_data_kadencji(nullptr)
    {
    printf("\nKonstruktor domyślny.\n");
    }

//Konstruktor.
Rada_Nadzorcza::Rada_Nadzorcza(int czl_l, int uch_l, int uch_lata, double bud_stan, time_t data_n, time_t data_o, string p, time_t data_k)
{
    f_ilosc_czlonkow = new int;
    *f_ilosc_czlonkow = czl_l;
    uchwaly_lata = new int;
    *uchwaly_lata = uch_l;
    uchwaly_liczba = new int;
    *uchwaly_liczba = uch_l;
    f_budzet_stan = new double;
    *f_budzet_stan = bud_stan;
    f_data_nast = new time_t;
    *f_data_nast = data_n;
    f_data_ost = new time_t;
    *f_data_ost = data_o;
    f_prezes = new string;
    *f_prezes = p;
    f_data_kadencji = new time_t;
    *f_data_kadencji = data_k;
}

//Konstruktor kopiujacy.
Rada_Nadzorcza::Rada_Nadzorcza(Rada_Nadzorcza& kopia){
    this->f_ilosc_czlonkow = new int(*(kopia.f_ilosc_czlonkow));
    this->uchwaly_lata = new int(*(kopia.uchwaly_lata));
    this->uchwaly_liczba = new int(*(kopia.uchwaly_liczba));
    this->f_budzet_stan = new double(*(kopia.f_budzet_stan));
    this->f_data_nast = new time_t(*(kopia.f_data_nast));
    this->f_data_ost = new time_t(*(kopia.f_data_ost));
    this->f_prezes = new string(*(kopia.f_prezes));
    this->f_data_kadencji = new time_t(*(kopia.f_data_kadencji));

    //Czy to jest potrzebne teraz ze wzgledu na to co na gorze?
    if (kopia.f_budzet_stan != nullptr){     
        f_budzet_stan = new double;
        *f_budzet_stan = *kopia.f_budzet_stan;
    }
    else{
        f_budzet_stan = nullptr;
    }

    if (kopia.f_prezes != nullptr){     
        f_prezes = new string;
        *f_prezes = *kopia.f_prezes;
    }
    else{
        f_prezes = nullptr;
    }
    

    f_ilosc_czlonkow = rezerwuj(&kopia.f_ilosc_czlonkow);
    uchwaly_lata = rezerwuj(&kopia.uchwaly_lata);
    uchwaly_liczba = rezerwuj(&kopia.uchwaly_liczba);
    f_data_nast = rezerwuj(&kopia.f_data_nast);
    f_data_ost = rezerwuj(&kopia.f_data_ost);
    f_data_kadencji = rezerwuj(&kopia.f_data_kadencji);
}

//Funkcje rezerwujace pamiec.
int * Rada_Nadzorcza::rezerwuj( int ** Wskaznik){
    int *Ret;
    if (*Wskaznik == nullptr) 
        Ret = nullptr;
    else{
        Ret = new int;
        *Ret = **Wskaznik;
    }
    return Ret;
}

time_t * Rada_Nadzorcza::rezerwuj( time_t ** Wskaznik){
    time_t *Ret;
    if (*Wskaznik == nullptr) 
        Ret = nullptr;
    else{
        Ret = new time_t;
        *Ret = **Wskaznik;
    }
    return Ret;
}

//Konstruktor przenoszacy.
Rada_Nadzorcza::Rada_Nadzorcza(Rada_Nadzorcza&& other):          
    f_ilosc_czlonkow(nullptr),
    uchwaly_liczba(nullptr), 
    uchwaly_lata(nullptr), 
    f_budzet_stan(nullptr), 
    f_data_nast(nullptr),
    f_data_ost(nullptr),
    f_prezes(nullptr),
    f_data_kadencji(nullptr)
{              
    f_ilosc_czlonkow = other.f_ilosc_czlonkow;
    uchwaly_lata = other.uchwaly_lata;
    uchwaly_liczba = other.uchwaly_liczba;
    f_budzet_stan = other.f_budzet_stan;
    f_data_nast = other.f_data_nast;
    f_data_ost = other.f_data_ost;
    f_prezes = other.f_prezes;
    f_data_kadencji = other.f_data_kadencji;

    other.f_ilosc_czlonkow = nullptr;
    other.uchwaly_lata = nullptr;
    other.uchwaly_liczba = nullptr;
    other.f_budzet_stan = nullptr;
    other.f_data_nast = nullptr;
    other.f_data_ost = nullptr;
    other.f_prezes = nullptr;
    other.f_data_kadencji = nullptr;
}    


//Konstruktor konwertujacy.
Rada_Nadzorcza::Rada_Nadzorcza(int parametr){
}

//Dekonstruktor
Rada_Nadzorcza::~Rada_Nadzorcza(){
    printf("\nDestruktor.\n");
    if (f_ilosc_czlonkow != nullptr) delete f_ilosc_czlonkow;
    if (uchwaly_lata != nullptr) delete uchwaly_lata;
    if (f_ilosc_czlonkow != nullptr) delete f_ilosc_czlonkow;
    if (uchwaly_liczba != nullptr) delete uchwaly_liczba;
    if (f_data_nast != nullptr) delete f_data_nast;
    if (f_data_ost != nullptr) delete f_data_ost;
    if (f_prezes != nullptr) delete f_prezes;
    if (f_data_kadencji != nullptr) delete f_data_kadencji;
}


//..................................................................................................................................
int Rada_Nadzorcza::ilosc_czlonkow(void) {                      //Odczytanie liczby członków. 
    return *f_ilosc_czlonkow;
    }

void Rada_Nadzorcza::l_powolanych(int wartosc){                 //Określenie liczby członków powołanych przez walne zgromadzenie.
    if (f_ilosc_czlonkow != nullptr){
        if (wartosc >= 0){
            *f_ilosc_czlonkow=wartosc;
        }
    }
}     

void Rada_Nadzorcza::l_odwolanych(int wartosc){                 //Określenie liczby członków odwołanych przez walne zgromadzenie.
    if (*f_ilosc_czlonkow >= wartosc && wartosc >= 0){
        *f_ilosc_czlonkow -= wartosc;
    }
}
      

void Rada_Nadzorcza::dodaj_uchwaly(int wartosc){                //Określenia liczby uchwał wydanych w poprzednim roku.
    if (wartosc >= 0){
        *uchwaly_lata += 1;
        *uchwaly_liczba += wartosc;
    }
}

float Rada_Nadzorcza::sr_uchwal(void){                          //Odczytanie średniej liczby uchwał ze wszystkich lat działania rady.
    return uchwaly_lata > 0 ? (*uchwaly_liczba / *uchwaly_lata) : 0.0; 
}


double Rada_Nadzorcza::budzet_stan(void){                       //Odczytanie aktualnego stanu budżetu.
    return *f_budzet_stan;
}

void Rada_Nadzorcza::budzet_wplyw(double wartosc){              //Określenia wpływu do budżetu.
    if (wartosc >= 0){
        *f_budzet_stan=wartosc;
    }
}     

void Rada_Nadzorcza::budzet_wydatki(double wartosc){            //Określenia wydatków z budżetu.
    if (*f_budzet_stan >= wartosc && wartosc >= 0){
        *f_budzet_stan -= wartosc;
    }
}


void Rada_Nadzorcza::data_nast(time_t wartosc){                 //Określenie daty planowanego zgromadzenia rady.
    if (wartosc > time(0)){
        *f_data_nast = wartosc;
    }
}

time_t Rada_Nadzorcza::data_ost(void){                          //Odczytanie daty ostatniego zgromadzenia.
    time_t tmp = *f_data_ost;
    *f_data_ost = *f_data_nast;
    *f_data_nast = 0;
    return tmp;
}


time_t Rada_Nadzorcza::data_nast(void){                         //Odczytanie daty następnego zgromadzenia.
    time_t tmp = *f_data_nast;
    *f_data_ost = tmp;
    *f_data_nast = 0;
    return tmp;
}


string Rada_Nadzorcza::prezes(void){                            //Odczytanie nazwiska i imienia prezesa.
    return *f_prezes;
}

time_t Rada_Nadzorcza::data_kadencji(void){                     //Odczytanie daty kadencji.
    return *f_data_kadencji;
}

void Rada_Nadzorcza::prezes_nominacja(string wartosc){          //Określenie nazwiska i imienia prezesa oraz daty kadencji.
    *f_prezes = wartosc;
    *f_data_kadencji = time(0);
    }