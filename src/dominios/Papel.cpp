#ifndef PAPEL_CPP_INCLUDED
#define PAPEL_CPP_INCLUDED

#include <dominios/Papel.hpp>
#include <string>
#include <stdexcept>

void Papel::validar(std::string valor)
{
    if (valor != "DESENVOLVEDOR" &&
        valor != "MESTRE_SCRUM" &&
        valor != "PROPRIETARIO_DE_PRODUTO")
    {
        throw std::invalid_argument("Papel invalido: deve ser DESENVOLVEDOR, MESTRE_SCRUM ou PROPRIETARIO_DE_PRODUTO");
    }
    return;
}

#endif // PAPEL_CPP_INCLUDED
