#ifndef ARCVHIVO_H
#define ARCVHIVO_H
#include<string>
#include<fstream>
#include "inventario.h"

using namespace std;

class Archivo
{
    private:
        
        string nombreTxt;
        bool existenciaArchivo;

    public:
        //Pre:Debe recibir el nombre del Archivo.
        //Post: crea la Lista.
        Archivo(string nombreArchivo);

        //Pre:-
        //Post:devuelve el estado del la variable existeciaArchivo, tiene almacenada si el archivo se leyo correctamente.
        bool getArchivoValido(); 

        //Pre:
        //Post:Recorre el txt de forma polimorfica.
        virtual void leerArchivo(string nombre) = 0;

        //Pre:
        //Post:retorna el nombre del archivo.
        string devolverNombre();

        virtual ~Archivo() = 0;
        
    private:
        
        //Pre:Debe recibir el nombre del Archivo.
        //Post:valida si existe el Archivo.
        void validarArchivo();

};

#endif