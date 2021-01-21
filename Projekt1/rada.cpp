#include <iostream>
#include <stdio.h>
#include <time.h>
#include "rada.h"
using namespace std;

Rada_Nadzorcza::Rada_Nadzorcza(void){
    f_ilosc_czlonkow = 0;
    uchwaly_liczba=0;
    uchwaly_lata=0;
    f_budzet_stan = 0;
    f_data_nast=0;
    f_data_ost=0;
    f_prezes = "";
    f_data_kadencji=0;

}

int Rada_Nadzorcza::ilosc_czlonkow(void) { 
    return f_ilosc_czlonkow;
    }

void Rada_Nadzorcza::l_powolanych(int wartosc){     //określenie liczby członków powołanych przez walne zgromadzenie.
    if (wartosc >= 0){
        f_ilosc_czlonkow=wartosc;
    }
}     

void Rada_Nadzorcza::l_odwolanych(int wartosc){     //określenia liczby członków odwołanych przez walne zgromadzenie.
    if (f_ilosc_czlonkow >= wartosc && wartosc >= 0){
        f_ilosc_czlonkow -= wartosc;
    }
}
      

void Rada_Nadzorcza::dodaj_uchwaly(int wartosc){        // określenia liczby uchwał wydanych w poprzednim roku.
    if (wartosc >= 0){
        uchwaly_lata += 1;
        uchwaly_liczba += wartosc;
    }
}

float Rada_Nadzorcza::sr_uchwal(void){           //odczytania średniej liczby uchwał ze wszystkich lat działania rady.
    return uchwaly_lata > 0 ? uchwaly_liczba/uchwaly_lata : 0.0;
}


double Rada_Nadzorcza::budzet_stan(void){              //odczytania aktualnego stanu budżetu.
    return f_budzet_stan;
}

void Rada_Nadzorcza::budzet_wplyw(double wartosc){            //określenia wpływu do budżetu.
    if (wartosc >= 0){
        f_budzet_stan=wartosc;
    }
}     

void Rada_Nadzorcza::budzet_wydatki(double wartosc){          //określenia wydatków z budżetu.
    if (f_budzet_stan >= wartosc && wartosc >= 0){
        f_budzet_stan -= wartosc;
    }
}


void Rada_Nadzorcza::data_nast(time_t wartosc){        //określenia daty planowanego zgromadzenia rady.
    if (wartosc > time(0)){
        f_data_nast = wartosc;
    }
}

time_t Rada_Nadzorcza::data_ost(void){        //odczytania daty ostatniego zgromadzenia.
    time_t tmp = f_data_ost;
    f_data_ost = f_data_nast;
    f_data_nast = 0;
    return tmp;
}


time_t Rada_Nadzorcza::data_nast(void){
    time_t tmp = f_data_nast;
    f_data_ost = tmp;
    f_data_nast = 0;
    return tmp;
}


string Rada_Nadzorcza::prezes(void){        //odczytuje nazwisko i imię prezesa
    return f_prezes;
}

time_t Rada_Nadzorcza::data_kadencji(void){     //odczytuje date kadencji
    return f_data_kadencji;
}

void Rada_Nadzorcza::prezes_nominacja(string wartosc){      //określa nazwisko prezesa i date kadencji
    f_prezes=wartosc;
    f_data_kadencji = time(0);

}