#ifndef PAPEL_CPP_INCLUDED
#define PAPEL_CPP_INCLUDED

#include "Papel.hpp"

bool Papel::validar(string valor)
{
    return valor == "DESENVOLVEDOR" ||
           valor == "MESTRE_SCRUM" ||
           valor == "PROPRIETARIO_DE_PRODUTO";
}

#endif // PAPEL_CPP_INCLUDED
