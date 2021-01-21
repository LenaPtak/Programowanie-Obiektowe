#ifndef Logger_h
#define Logger_h

#include <iostream>
using namespace std;

class Logger
{
private:
    /* data */

public:
    void log(string);
    Logger(void);
    Logger(bool debug);
    ~Logger();
};

#endif