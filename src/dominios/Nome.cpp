#ifndef NOME_CPP_INCLUDED
#define NOME_CPP_INCLUDED

#include <dominios/Nome.hpp>
#include <string>
#include <stdexcept>
#include <util/StringUtils.hpp>

using namespace std;

void Nome::validar(string valor)
{
    if (valor.empty() || valor.length() > 10)
    {
        throw invalid_argument("Nome invalido: deve ter entre 1 e 10 caracteres");
    }

    for (size_t i = 0; i < valor.length(); i++)
    {
        char caracter = valor[i];
        if (!StringUtils::isChar(caracter, true) && !StringUtils::isIn(caracter, " "))
        {
            throw invalid_argument("Nome invalido: caractere invalido encontrado");
        }

        if (StringUtils::isIn(caracter, " ") && (i + 1 >= valor.length() || !StringUtils::isChar(valor[i + 1], true)))
        {
            throw invalid_argument("Nome invalido: espaco em posicao invalida");
        }
    }

    if (StringUtils::isIn(valor[0], " ") || StringUtils::isIn(valor[valor.length() - 1], " "))
    {
        throw invalid_argument("Nome invalido: nao pode comecar ou terminar com espaco");
    }

    return;
}

#endif // NOME_CPP_INCLUDED