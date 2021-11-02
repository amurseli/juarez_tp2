#ifndef CASILLEROCTRANSITABLE_H
#define CASILLEROCTRANSITABLE_H
#include <string>
#include <iostream>
#include "casillero.h"

using namespace std;

class CasilleroTransitable : public Casillero
{
private:
    string prueba;
public:
    CasilleroTransitable(string elemento);
    
    void queSoy();

    virtual ~CasilleroTransitable();
};

#endif