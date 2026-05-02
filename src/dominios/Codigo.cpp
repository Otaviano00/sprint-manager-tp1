#ifndef CODIGO_CPP_INCLUDED
#define CODIGO_CPP_INCLUDED

#include "Codigo.hpp"
#include <iostream>
#include <stdexcept>

bool Codigo::validar(string valor)
{
    if (valor.length() != 5)
    {
        throw std::invalid_argument("Tamanho diferente de 5");
    }

    int numMaiusculos = 2;
    for (int i = 0; i < numMaiusculos; i++)
    {
        if ('A' > valor[i] || 'Z' < valor[i])
        {
           throw std::invalid_argument("Não é letra maísucula");
        }
    }

    for (int i = numMaiusculos; i < valor.length(); i++)
    {
        if ('0' > valor[i] || '9' < valor[i])
        {
            throw std::invalid_argument("Não é numero");
        }
    }

    return true;
}

#endif // CODIGO_CPP_INCLUDED