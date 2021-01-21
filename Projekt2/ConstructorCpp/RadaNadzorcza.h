#include <iostream>
#include "Logger.h"
using namespace std;

class Rada_Nadzorcza: Logger{

private:
    int* f_ilosc_czlonkow;
    int* uchwaly_lata;
    int* uchwaly_liczba;
    double* f_budzet_stan;
    time_t* f_data_nast;
    time_t* f_data_ost;
    string* f_prezes;
    time_t* f_data_kadencji;


public:

    void log(string);

    int  ilosc_czlonkow(void);                  //Odczytanie liczby członków.

    void l_powolanych(int wartosc);             //Określenie liczby członków powołanych przez walne zgromadzenie.
    void l_odwolanych(int wartosc);             //Określenie liczby członków odwołanych przez walne zgromadzenie.

    void dodaj_uchwaly(int wartosc);            //Określenia liczby uchwał wydanych w poprzednim roku.
    float sr_uchwal(void);                      //Odczytanie średniej liczby uchwał ze wszystkich lat działania rady.

    double budzet_stan(void);                   //Odczytanie aktualnego stanu budżetu.
    void budzet_wplyw(double wartosc);          //Określenia wpływu do budżetu.
    void budzet_wydatki(double wartosc);        //Określenia wydatków z budżetu.

    void data_nast(time_t wartosc);             //Określenie daty planowanego zgromadzenia rady.
    time_t data_ost(void);                      //Odczytanie daty ostatniego zgromadzenia.
    time_t data_nast(void);                     //Odczytanie daty następnego zgromadzenia.

    time_t data_kadencji(void);                 //Odczytanie daty kadencji.
    void prezes_nominacja(string wartosc);      //Określenie nazwiska i imienia prezesa oraz daty kadencji.
    string prezes(void);                        //Odczytanie nazwiska i imienia prezesa.


    int* rezerwuj(int **Wskaznik);              //Sprawdza pamiec (int).
    time_t* rezerwuj(time_t **Wskaznik);        //Sprawdza pamiec (time_t).


Rada_Nadzorcza(void);               //Domyslny           
Rada_Nadzorcza(int czl_l, int uch_l, int uch_lata = 0, double bud_stan = 0, time_t data_n = 0, time_t data_o = 0, string p = "", time_t data_k = 0);      //Konstruktor.
Rada_Nadzorcza(Rada_Nadzorcza& kopia);                                //konstruktor kopiujący.
Rada_Nadzorcza(Rada_Nadzorcza&& other);                               //konstruktor przenoszacy.
Rada_Nadzorcza(int parametr);                                         //Konstruktor konwertujacy.

~Rada_Nadzorcza();                                                          //Dekonstruktor
};
