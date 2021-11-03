#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <string>

using namespace std;

class Edificio
{
private:
    string edificio;
    int posicionX,posicionY;

public:
    Edificio (string tipoEdificio, int coordX, int coordY);
};


#endif //EDIFICIO_H
