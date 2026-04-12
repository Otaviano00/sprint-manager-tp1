#ifndef CODIGO_CPP_INCLUDED
#define CODIGO_CPP_INCLUDED

#include "Codigo.hpp"
#include <iostream>

bool Codigo::validar(string valor)
{
    if (valor.length() != 5)
    {
        return false;
    }

    int numMaiusculos = 2;
    for (int i = 0; i < numMaiusculos; i++)
    {
        if ('A' > valor[i] || 'Z' < valor[i])
        {
            return false;
        }
    }

    for (int i = numMaiusculos; i < valor.length(); i++)
    {
        if ('0' > valor[i] || '9' < valor[i])
        {
            return false;
        }
    }

    return true;
}

#endif // CODIGO_CPP_INCLUDED