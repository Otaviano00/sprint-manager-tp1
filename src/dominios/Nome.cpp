#ifndef NOME_CPP_INCLUDED
#define NOME_CPP_INCLUDED

#include <dominios/Nome.hpp>
#include <stdexcept>
#include <string>
#include <util/StringUtils.hpp>

using namespace std;

bool Nome::validar(string valor)
{
    if (valor.empty() || valor.length() > 10)
    {
        throw std::invalid_argument("Nome invalido: deve ter entre 1 e 10 caracteres");
    }

    for (size_t i = 0; i < valor.length(); i++)
    {
        char caracter = valor[i];
        if (!StringUtils::isChar(caracter, true) && !StringUtils::isIn(caracter, " "))
        {
            throw std::invalid_argument("Nome invalido: caracter invalido encontrado");
        }

        if (StringUtils::isIn(caracter, " ") && (i + 1 >= valor.length() || !StringUtils::isChar(valor[i + 1], true)))
        {
            throw std::invalid_argument("Nome invalido: espaco em branco invalido");
        }
    }

    if (StringUtils::isIn(valor[0], " ") || StringUtils::isIn(valor[valor.length() - 1], " "))
    {
        throw std::invalid_argument("Nome invalido: nao pode comecar ou terminar com espaco");
    }

    return true;
}

#endif // NOME_CPP_INCLUDED