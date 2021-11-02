#include "ubicaciones.h"

using namespace std;

Ubicaciones::Ubicaciones(string nombre):Archivo(nombre){
    leerArchivo(nombre);
}
void Ubicaciones::leerArchivo(string nombre)
{

    fstream documento(nombre, ios::in);

    string nombreEdificio;
    string coordX, coordY;
    int cleanCoordX, cleanCoordY, cantDigitos, inicioNumero;
    while (documento >> nombreEdificio)
    {

        documento >> coordX;
        documento >> coordY;

        coordX = coordX.substr(1);
        coordX.pop_back();
        cleanCoordX = atoi(coordX.c_str());

        coordY.pop_back();
        cleanCoordY = atoi(coordY.c_str());


       cout << cleanCoordX << " " << cleanCoordY << " " << nombreEdificio << endl;

    }

    documento.close();
}