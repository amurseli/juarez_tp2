#ifndef TP1_MENU_H
#define TP1_MENU_H

#include "edificios.h"
#include "matriz.h"
const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA = 10;
const int CONSTRUIR_EDIFICIOS = 1;
const int MOSTRAR_EDIFICIOS_CONSTRUIDOS = 2;
const int MOSTRAR_EDIFICIOS = 3;
const int DEMOLER_EDIFICIO = 4;
const int MOSTRAR_MAPA = 5;
const int CONSULTAR_COORDENADA = 6;
const int MOSTRAR_INVENTARIO = 7;
const int RECOLECTAR = 8;
const int LLUVIA_DE_RECUROS = 9;
const int SALIR = 10;

//pre: -
//post: Imprime por pantalla el menu
void mostrar_menu();

//pre: -
//post: Realiza la opcion pedida
void procesar_opcion(Matriz* punteroMatriz, int opcion_elegida);

//pre:-
//post: Frena el programa hasta recibir un input
void presione_enter();

//pre: -
//post: devuelve true si la opcion recibida esta en el rango valido y sino devuelve false.
bool es_opcion_valida(int elegida);

#endif //TP1_MENU_H
