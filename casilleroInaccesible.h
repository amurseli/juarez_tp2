#ifndef CASILLEROCINACCESIBLE_H
#define CASILLEROCINACCESIBLE_H
#include <string>
#include <iostream>
#include "casillero.h"

using namespace std;

class CasilleroInaccesible : public Casillero
{
private:
    string prueba;
public:
    CasilleroInaccesible(string elemento);
    void queSoy();
    virtual ~CasilleroInaccesible();
};

#endif