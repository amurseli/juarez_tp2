#ifndef ARCVHIVO_H
#define ARCVHIVO_H
#include<string>
#include<fstream>
#include"array.h"

using namespace std;

class Archivo
{
    private:
        
        string nombre;
        bool existenciaArchivo;
        Array<string>* contenido = NULL;

    public:
        //Pre:Debe recibir el nombre del Archivo.
        //Post: crea la Lista.
        Archivo(string nombreArchivo);

        //Pre:
        //Post: 
        void crearContenido();

        //Pre:-
        //Post:devuelve el estado del la variable existeciaArchivo.
        bool getArchivoValido(); 

        //Pre:
        //Post: 
        virtual void leerArchivo(string nombre) = 0;

        //Pre:
        //Post: 
        void agregarElementoArray(string elemento);

        //Pre:-
        //Post:Muestra el array
        void mostrarContenido();

        ~Archivo();
        

    private:
        
        //Pre:Debe recibir el nombre del Archivo.
        //Post:valida si existe el Archivo.
        void validarArchivo();


};

#endif