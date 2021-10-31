
#include <iostream>
#include <string>

using namespace std;

class Casillero
{
private:
    string tipoTerreno;

public:
    Casillero();
    Casillero(string letraMapa);
    string mostrarTipoTerreno ();
};