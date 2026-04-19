#ifndef TEXTO_CPP_INCLUDED
#define TEXTO_CPP_INCLUDED

#include "Texto.hpp"
#include <string>
#include "../util/StringUtils.hpp"

using namespace std;

bool Texto::validar(string valor)
{
    if (valor.length() > 40)
    {
        return false;
    }

    if (StringUtils::isIn(valor[0], ",. ") || StringUtils::isIn(valor[valor.length() - 1], ",. "))
    {
        return false;
    }

    for (size_t i = 0; i < valor.length(); i++)
    {
        char caractere = valor[i];
        bool isChar = StringUtils::isChar(caractere, true);
        bool isDigit = StringUtils::isDigit(caractere);
        bool isIn = StringUtils::isIn(caractere, ",. ");

        if (!isChar && !isDigit && !isIn)
        {
            return false;
        }

        if (StringUtils::isIn(caractere, ",.") && StringUtils::isIn(valor[i + 1], ",."))
        {
            return false;
        }

        if (caractere == ' ' && !StringUtils::isChar(valor[i + 1], true) && !StringUtils::isDigit(valor[i + 1]))
        {
            return false;
        }
    }

    return true;
}

#endif // TEXTO_CPP_INCLUDED