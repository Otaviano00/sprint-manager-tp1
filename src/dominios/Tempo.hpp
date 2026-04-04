#ifndef TEMPO_HPP_INCLUDED
#define TEMPO_HPP_INCLUDED

#include "Dominio.hpp"

class Tempo : public Dominio<int>
{
private:
    bool validar(int valor);
};

#endif // TEMPO_HPP_INCLUDED