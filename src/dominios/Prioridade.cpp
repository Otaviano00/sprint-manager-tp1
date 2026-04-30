#ifndef PRIORIDADE_CPP_INCLUDED
#define PRIORIDADE_CPP_INCLUDED

#include <dominios/Prioridade.hpp>
#include <string>
#include <stdexcept>

void Prioridade::validar(std::string valor)
{
    if (valor != "ALTA" &&
        valor != "MEDIA" &&
        valor != "BAIXA")
    {
        throw std::invalid_argument("Prioridade invalida: deve ser ALTA, MEDIA ou BAIXA");
    }
    return;
}

#endif // PRIORIDADE_CPP_INCLUDED