#ifndef PRIORIDADE_CPP_INCLUDED
#define PRIORIDADE_CPP_INCLUDED

#include <dominios/Prioridade.hpp>
#include <stdexcept>
#include <string>

bool Prioridade::validar(std::string valor)
{
    if (valor != "ALTA" &&
        valor != "MEDIA" &&
        valor != "BAIXA")
    {
        throw std::invalid_argument("Prioridade invalida: valor deve ser ALTA, MEDIA ou BAIXA");
    }
    return true;
}

#endif // PRIORIDADE_CPP_INCLUDED