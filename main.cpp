#include <iostream>
#include<fstream>
#include<string>
#include"materiales.h"
#include"array.h"
#include"edificios.h"

using namespace std;

const string PATH_MATERIALES = "materiales.txt";
const string PATH_EDIFICIOS = "edificios.txt";

int main()
{
    materiales materialesTxt(PATH_MATERIALES);

    materialesTxt.mostarContenido();

    edificios edificiosTxt(PATH_EDIFICIOS);  

    edificiosTxt.mostarContenido();

    return 0;
}

