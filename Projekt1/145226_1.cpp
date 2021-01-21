 #include <iostream>
 #include <ctime>
 #include "rada.h"
 using namespace std;

char* time2string(time_t data, char* buf);

int main(){
    char buf[100];

    Rada_Nadzorcza* Rada1 = new Rada_Nadzorcza;
    printf("\nWszystko jest w porządku.\n");

    Rada1->l_powolanych(20);     //określenie liczby członków powołanych przez walne zgromadzenie.
    Rada1->l_odwolanych(10);     //określenia liczby członków odwołanych przez walne zgromadzenie.
    printf("Liczba członków: %d.\n", Rada1->ilosc_czlonkow());          //odczytania aktualnej liczby członków rady nadzorczej.

    Rada1->dodaj_uchwaly(45);   // określenia liczby uchwał wydanych w poprzednim roku.
    printf("Średnia uchwał to: %f.\n", (double)Rada1->sr_uchwal());              //odczytania średniej liczby uchwał ze wszystkich lat działania rady.

    Rada1->budzet_wplyw(20003.67);            //określenia wpływu do budżetu.
    Rada1->budzet_wydatki(15000.809);          //określenia wydatków z budżetu.
    printf("Stan budżetu to %f.\n", Rada1->budzet_stan());              //odczytania aktualnego stanu budżetu.

    Rada1->data_nast(time(0)+3);        //określenia daty planowanego zgromadzenia rady
    printf("Data następnego zgromadzenia to %s.\n", time2string(Rada1->data_nast(), buf));
    Rada1->data_nast(time(0)+6);
    printf("Data ostatniego zgromadzenia to %s.\n", time2string(Rada1->data_ost(), buf));        //odczytania daty ostatniego zgromadzenia.

    Rada1->prezes_nominacja("Mirosław Jarzębiarz");      //określa nazwisko prezesa i date kadencji    
    printf("Obecny prezes to %s, a jego data kadencji %s.\n", Rada1->prezes().c_str(), time2string(Rada1->data_kadencji(), buf));        //odczytuje nazwisko i imię prezesa

    delete Rada1;
    return(0);
 }

char* time2string(time_t data, char* buf){
    tm* ptm = localtime(&data);
    std::strftime(buf, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);
    return buf;
} 