#ifndef ESTADO_CPP_INCLUDED
#define ESTADO_CPP_INCLUDED

#include "Estado.hpp"
#include <string>

using namespace std;

bool Estado::validar(string valor)
{
    return valor == "A_FAZER" ||
           valor == "FAZENDO" ||
           valor == "FEITO";
}

#endif // ESTADO_CPP_INCLUDED
