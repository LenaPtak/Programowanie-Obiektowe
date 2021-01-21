#include <iostream>
#include <time.h>
#include <ctime>
#include "windows.h"
#include <unistd.h>
#include "RadaNadzorcza.h"
#include "Logger.h"
#include "Stopper.h"

using namespace std;

char* time2string(time_t data, char* buf);

void pokaz (Rada_Nadzorcza rada_nadzorcza){
    printf("\nCo powinny robic te funkcje? \n Podpunkt 14.\n");
}

void funkcja2 (const Rada_Nadzorcza &rada_nadzorcza){
    //...(implementacja)
}

void funkcja3 (Rada_Nadzorcza &rada_nadzorcza){
    //...(implementacja)
}

void funkcja4 (Rada_Nadzorcza &&rada_nadzorcza){
    //...(implementacja)
}

int main(){
    Rada_Nadzorcza rada1(12, 15, 8); //Czy powinnam dodać "= Rada_Nadzorcza();" ?
    rada1.l_powolanych(100);                    //Określenie liczby członków powołanych przez walne zgromadzenie.
    rada1.l_odwolanych(8);                      //Określenie liczby członków odwołanychs przez walne zgromadzenie.
    rada1.dodaj_uchwaly(15);
    rada1.budzet_wplyw(10000);
    rada1.budzet_wydatki(7000);
    rada1.data_nast(0);
    rada1.prezes_nominacja("Rafał Nowak");      //Określenie nazwiska i imienia prezesa oraz daty kadencji.
    //pokaz(rada1);

    //-----------------------------------------------------------------
    Stopper czas1;
    time_t start, stop, reset;
    start = czas1.time_start();
    sleep(2);
    stop = czas1.time_stop();
    czas1.time_reset(start);
    //czas1.time_show(*start, *stop);


    //-----------------------------------------------------------------
    Logger log1;
    //rada1.log(" to dzisiejsza data.\n"); // TO NIE DO KOŃCA DZIAŁA. DLACZEGO? Tu trzeba napisać szerszy komentarz.

    return(0);
 }