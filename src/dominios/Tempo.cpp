#ifndef TEMPO_CPP_INCLUDED
#define TEMPO_CPP_INCLUDED

#include <dominios/Tempo.hpp>
#include <stdexcept>

bool Tempo::validar(int valor)
{
    if (valor < 1 || valor > 365)
    {
        throw std::invalid_argument("Tempo deve estar entre 1 e 365");
    }

    return true;
}

#endif // TEMPO_CPP_INCLUDED