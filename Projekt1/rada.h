#include <iostream>

using namespace std;

class Rada_Nadzorcza{

private:
    int f_ilosc_czlonkow;
    int uchwaly_lata;
    int uchwaly_liczba;
    double f_budzet_stan;
    time_t f_data_nast;
    time_t f_data_ost;
    string f_prezes;
    time_t f_data_kadencji;


public:

    int  ilosc_czlonkow(void);          //odczytania aktualnej liczby członków rady nadzorczej.

    void l_powolanych(int wartosc);     //określenie liczby członków powołanych przez walne zgromadzenie.
    void l_odwolanych(int wartosc);     //określenia liczby członków odwołanych przez walne zgromadzenie.

    void dodaj_uchwaly(int wartosc);   // określenia liczby uchwał wydanych w poprzednim roku.
    float sr_uchwal(void);              //odczytania średniej liczby uchwał ze wszystkich lat działania rady.

    double budzet_stan(void);              //odczytania aktualnego stanu budżetu,
    void budzet_wplyw(double wartosc);            //określenia wpływu do budżetu,
    void budzet_wydatki(double wartosc);          //określenia wydatków z budżetu,

    void data_nast(time_t wartosc);        //określenia daty planowanego zgromadzenia rady
    time_t data_ost(void);        //odczytania daty ostatniego zgromadzenia.
    time_t data_nast(void);

    string prezes(void);        //odczytuje nazwisko i imię prezesa
    time_t data_kadencji(void);
    void prezes_nominacja(string wartosc);      //określa nazwisko prezesa i date kadencji

Rada_Nadzorcza(void);

};
