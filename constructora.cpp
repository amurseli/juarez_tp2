#include "constructora.h"

Constructora::Constructora(Edificios *&edificioTxt, Materiales *&materialesTxt, Matriz *&matrizOriginal)
{

    edificios = edificioTxt;
    materiales = materialesTxt;
    matriz = matrizOriginal;
}

void Constructora::construirEdificio()
{

    string nombreNuevoEdificio;
    bool entradaValida = false;

    do
    {
        cout << "Ingrese el nombre del nuevo edificio: ";
        cin >> nombreNuevoEdificio;
        entradaValida = edificios->validarEdificios(nombreNuevoEdificio);

        if (!entradaValida && (nombreNuevoEdificio!="1"))
            mostrarAviso();

    } while (!entradaValida && nombreNuevoEdificio != "1");

    if(entradaValida)
        avanzarConConstruccion(nombreNuevoEdificio);
    else{
        cout << "\n Oh, no construyes nada?, bueno, vuelve pronto la constructora de Andypolis necesita trabajar\n" << endl;
    }
}

void Constructora::avanzarConConstruccion(string nombreNuevoEdificio){

    bool coordenadasValidas = false, materialesValidos = false, validarTerrenoVacio = false, cantidadConstruida = false;
    string edificio;

    cantidadConstruida = validarMaximoEdificio(nombreNuevoEdificio);

    if(cantidadConstruida)
        materialesValidos = validarMateriales(nombreNuevoEdificio);
    else{
        cout << "\nOh, lamento traer malas noticias pero ya has alcanzo el maximo de construidos para este edificio: ";
    }

    if(materialesValidos)
        coordenadasValidas = ingresoDeCoordenadas();

    if(coordenadasValidas){
        edificio = matriz->devolverTipoEdificio(filaParaTrabajar,columnaParaTrabajar);
        validarTerrenoVacio = terrenoVacio(edificio);
    }
    
    if (validarTerrenoVacio){
        matriz->construirEdificio(filaParaTrabajar,columnaParaTrabajar,nombreNuevoEdificio);
        restarMateriales(nombreNuevoEdificio);
        cout << "\n EL EDIFICIO SE HA CONSTRUIDO\n" << endl;
    }
    else if (materialesValidos && (!validarTerrenoVacio)){
        cout << "\nAcaso has perdido la cabeza?, aqui ya hay un edificio: ";
    }
}

void Constructora::demolerEdificio(){

    bool coordenadaConfirmada = false;
    string nombreEdificio = VACIO, confirmacion = NO_CONFIRMADO;

    coordenadaConfirmada = ingresoDeCoordenadas();

    if(coordenadaConfirmada)
        nombreEdificio = (matriz->devolverTipoEdificio(filaParaTrabajar,columnaParaTrabajar));

    if(!terrenoVacio(nombreEdificio) && coordenadaConfirmada){
        cout << "\n el edificio en las coordenada es: " + nombreEdificio + " desea demolerlo?: " << endl;
        cout << "\n¿Desea construir? [s/n]: ";
        cin >> confirmacion;
    }
    else{
        cout << "\nEstas demente?, aqui no hay nada para demoler: \n";
    }

    if(confirmacion == CONFIRMADO){
        sumarMateriales(nombreEdificio);
        matriz->demolerEdificio(filaParaTrabajar,columnaParaTrabajar);
        cout << "\n EL EDIFICIO SE HA DEMOLIDO\n" << endl;
    }
}

bool Constructora::validarMaximoEdificio(string nombreNuevoEdificio){
    int maximaCantidadPermitida = 0, cantidadActual = 0;

    Inventario *inventarioDeEdificio = edificios->devolverInventario(nombreNuevoEdificio);

    maximaCantidadPermitida = inventarioDeEdificio->devolverMaximaCantidadPermitidos();

    cantidadActual = matriz->devolverCantidadEdificio(nombreNuevoEdificio);

    return(cantidadActual<maximaCantidadPermitida);    
}

bool Constructora::validarMateriales(string nombreNuevoEdificio)
{

    bool materialesValidos = false, confirmacion = false;

    Inventario *inventarioDeEdificio = edificios->devolverInventario(nombreNuevoEdificio);

    materialesValidos = materiales->validarMateriales(inventarioDeEdificio->devolverPiedra(), inventarioDeEdificio->devolverMadera(), inventarioDeEdificio->devolverMetal());

    if(materialesValidos)
    {
        confirmacion = confirmar(inventarioDeEdificio->devolverPiedra(), inventarioDeEdificio->devolverMadera(), inventarioDeEdificio->devolverMetal());
    }
    else{
        cout << "\n No tienes suficientes materiales" << endl;
    }

    return (confirmacion);
}

bool Constructora::confirmar(int piedraNecesaria, int maderaNecesaria, int metalNecesario)
{
    string confirmacion;

    cout << "\nLos materiales después de la construccion seran: " << endl;
    cout << "Piedra: " << materiales->devolverPiedra() - piedraNecesaria << endl;
    cout << "Madera: " << materiales->devolverMadera() - maderaNecesaria << endl;
    cout << "Metal: " << materiales->devolverMetal() - metalNecesario << endl;
    cout << "\n¿Desea construir? [s/n]: ";
    cin >> confirmacion;

    return (confirmacion == CONFIRMADO);
}

bool Constructora::ingresoDeCoordenadas()
{
    bool salidaSinCoordenada = false, coordOk = false;
    matriz->mostrarMatriz();
    do
    {
        cout << "Ingrese la coordenada fila: ";
        cin >> filaParaTrabajar;
        filaParaTrabajar--;

        if(filaParaTrabajar == -2){
            salidaSinCoordenada =  true;
            cout << "\nUsted ha salido" << endl;
        }
        else{
            cout << "Ingrese la coordenada columna: ";
            cin >> columnaParaTrabajar;
            columnaParaTrabajar--;
            coordOk = validarCoordenadas(filaParaTrabajar,columnaParaTrabajar);
        }

        if(coordOk){
            coordOk = matriz->validarTipoConstruible(filaParaTrabajar,columnaParaTrabajar);
            mostrarAvisoTerreno(coordOk);}

    } while (!coordOk && !salidaSinCoordenada);

    return (coordOk);
}

bool Constructora::validarCoordenadas(int coord1, int coord2)
{
    bool coordsOk = false;

    if(coord1 < matriz->devolverMaxFil() && coord2 < matriz->devolverMaxCol() && coord1 >= 0 && coord2 >= 0)
    {   
        coordsOk = true;
    }
    else{
        cout << "\nEsa no es una coordenada valida - Intentalo de nuevo o sal con un -1 :)" << endl;
        cout << "Filas disponibles: -> (1, " <<  matriz->devolverMaxFil() << ") \nColumnas disponibles: -> (1, " << matriz->devolverMaxCol() << ")" << endl;
    }

    return coordsOk;
}

void Constructora::restarMateriales(string nombreNuevoEdificio){

    Inventario *inventarioDeEdificio = edificios->devolverInventario(nombreNuevoEdificio);
    
    materiales->restarPiedra(inventarioDeEdificio->devolverPiedra());
    materiales->restarMadera(inventarioDeEdificio->devolverMadera());
    materiales->restarMetal(inventarioDeEdificio->devolverMetal());
}

void Constructora::sumarMateriales(string nombreEdificio){

    Inventario *inventarioDeEdificio = edificios->devolverInventario(nombreEdificio);
    
    materiales->sumarPiedra(inventarioDeEdificio->devolverPiedra()/2);
    materiales->sumarMadera(inventarioDeEdificio->devolverMadera()/2);
    materiales->sumarMetal(inventarioDeEdificio->devolverMetal()/2);

}

void Constructora::mostrarAvisoTerreno(bool aviso){

    if(!aviso)
        cout << "\nEste no es un casillero construible,  para salir presione -1" << endl;
}

void Constructora::mostrarAviso()
{

    cout << "\n EL edificio que intenta crear no existe, para salir presione 1" << endl;
}

bool Constructora::terrenoVacio(string nombreEdificio){

    return (nombreEdificio == VACIO);
}

void Constructora::preguntarCoordenadas() {}