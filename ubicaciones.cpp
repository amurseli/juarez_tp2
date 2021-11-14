#include "ubicaciones.h"


using namespace std;

Ubicaciones::Ubicaciones(string nombre, Matriz* &matriz):Archivo(nombre){
    punteroMatriz = matriz;

    if(getArchivoValido())
        leerArchivo(nombre);

}
void Ubicaciones::leerArchivo(string nombre)
{
    fstream documento(nombre, ios::in);

    string nombreEdificio, segundoNombre;
    string coordX, coordY;
    int cleanCoordX, cleanCoordY;
    while (documento >> nombreEdificio)
    {   
        if(nombreEdificio == "planta"){
            documento >> segundoNombre;
            nombreEdificio = nombreEdificio + " " + segundoNombre;
        }

        documento >> coordX;
        documento >> coordY;

        cleanCoordX = arreglarCoordenadaX(coordX);
        cleanCoordY = arreglarCoordenadaY(coordY);

        punteroMatriz->construirEdificio(cleanCoordX,cleanCoordY,nombreEdificio);
    }

    documento.close();
}

Ubicaciones* Ubicaciones::devolverPuntero() {
    return (this);
}

void Ubicaciones::escribirArchivo()
{

    fstream documento(devolverNombre(), ios::out);

    string nombreEdificio;
    string coordX, coordY;

    for (int i = 0; i < punteroMatriz->devolverMaxFil(); i++)
    {
        for (int j = 0; j < punteroMatriz->devolverMaxCol(); j++)
        {
            nombreEdificio = punteroMatriz->devolverTipoEdificio(i,j);
            if(nombreEdificio != VACIO)
            {
                coordX = to_string(i);
                coordY = to_string(j);
                documento << nombreEdificio + " " + "(" + coordX + ", " + coordY + ")" << endl;
            }
        }
    }

    documento.close();
}

int Ubicaciones::arreglarCoordenadaX(string coordX){

        coordX = coordX.substr(1);
        coordX.pop_back();

        return (atoi(coordX.c_str()));
}

int Ubicaciones::arreglarCoordenadaY(string coordY){

        coordY.pop_back();
        return (atoi(coordY.c_str()));       
}

Ubicaciones::~Ubicaciones(){}
