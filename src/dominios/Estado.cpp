#ifndef ESTADO_CPP_INCLUDED
#define ESTADO_CPP_INCLUDED

#include <dominios/Estado.hpp>
#include <string>
#include <stdexcept>

using namespace std;

bool Estado::validar(string valor)
{
    if (valor == "A FAZER" ||
        valor == "FAZENDO" ||
        valor == "FEITO")
    {
        return true;
    }

    throw std::invalid_argument("Estado inválido: " + valor);
}

#endif // ESTADO_CPP_INCLUDED
