#ifndef PRIORIDADE_CPP_INCLUDED
#define PRIORIDADE_CPP_INCLUDED

#include "Prioridade.hpp"

bool Prioridade::validar(string valor)
{
    return valor == "ALTA" ||
           valor == "MEDIA" ||
           valor == "BAIXA";
}

#endif // PRIORIDADE_CPP_INCLUDED