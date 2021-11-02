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

    while (documento >> nombreEdificio)
    {
        (getline(documento,coordX,','));
        (getline(documento,coordY,')'));
        int coordXInt = atoi(coordX.c_str());
        int coordYInt = atoi(coordY.c_str());
        documento >> coordX;
        documento >> coordY;

        cout << coordXInt << " " << coordYInt << endl;

    }

    documento.close();
}