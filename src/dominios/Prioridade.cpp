#ifndef PRIORIDADE_CPP_INCLUDED
#define PRIORIDADE_CPP_INCLUDED

#include <dominios/Prioridade.hpp>
#include <string>

bool Prioridade::validar(std::string valor)
{
    return valor == "ALTA" ||
           valor == "MEDIA" ||
           valor == "BAIXA";
}

#endif // PRIORIDADE_CPP_INCLUDED