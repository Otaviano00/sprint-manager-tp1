#ifndef TEMPO_CPP_INCLUDED
#define TEMPO_CPP_INCLUDED

#include <dominios/Tempo.hpp>

bool Tempo::validar(int valor)
{
    if (valor < 1 || valor > 365)
    {
        return false;
    }
    return true;
}

#endif // TEMPO_CPP_INCLUDED