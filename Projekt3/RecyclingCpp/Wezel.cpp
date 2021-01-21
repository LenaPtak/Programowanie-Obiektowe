#include <iostream>
#include <memory>
#include <stdio.h>
#include <time.h>
#include "Wezel.h"
using namespace std;

shared_ptr<Wezel> wskaznik(new Wezel);


Wezel::Wezel(){             //Konstruktor domyślny.
    printf("Konstruktor");
}        
Wezel::~Wezel(){        //Destruktor.
    std::cout << "Destrukcja obiektu" << std::endl;
}