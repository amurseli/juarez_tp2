#include <string>
#include "materiales.h"
#include "edificios.h"
#include "mapa.h"
#include "menu.h"

using namespace std;

int main()
{
    Menu* menu = new Menu();

    menu->mostrarMensajeError();

    delete menu;

    return 0;
}
