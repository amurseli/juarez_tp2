#ifndef EDIFICIO_H
#define EDIFICIO_H
#include <iostream>

#include <string>

using namespace std;

class Edificio
{
private:

    string nombre;

public:
    
    Edificio (string tipoEdificio);

    string devolverNombre();

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    void recolectar();

    //virtual ~Edificio();

};


#endif //EDIFICIO_H
