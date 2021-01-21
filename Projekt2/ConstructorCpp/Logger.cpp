#include <iostream>
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <ctime> 
#include <time.h>
#include "RadaNadzorcza.h"
#include "Logger.h"
#include "Stopper.h"
using namespace std;

Logger::Logger(void){}

Logger::Logger(bool debug)
{
    if (debug == true) {
        //Jak dać pozwolenie funkcji log na wypisywanie wartosci na std wyjscie?
    }
}

Logger::~Logger()
{
}

//......................................................................................

void Logger::log(string ciag){
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << dt << ciag << endl;

}