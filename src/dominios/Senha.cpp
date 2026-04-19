#ifndef SENHA_CPP_INCLUDED
#define SENHA_CPP_INCLUDED

#include "Senha.hpp"
#include <string>
#include "../util/StringUtils.hpp"

using namespace std;

bool Senha::validar(string valor)
{
    if (valor.length() != 6)
    {
        return false;
    }

    int countMaiusc = 0, countMinusc = 0, countDigito = 0;

    for (size_t i = 0; i < valor.length(); i++)
    {
        char caractere = valor[i];
        if (!StringUtils::isChar(caractere, true) && !StringUtils::isDigit(caractere))
        {
            return false;
        }

        if (StringUtils::isChar(caractere, true) && StringUtils::isChar(valor[i + 1], true))
        {
            return false;
        }

        if (StringUtils::isDigit(caractere) && StringUtils::isDigit(valor[i + 1]))
        {
            return false;
        }

        if (caractere >= 'a' && caractere <= 'z')
        {
            countMinusc++;
        }

        if (caractere >= 'A' && caractere <= 'Z')
        {
            countMaiusc++;
        }

        if (StringUtils::isDigit(caractere))
        {
            countDigito++;
        }
    }

    if (countDigito == 0 || countMaiusc == 0 || countMinusc == 0)
    {
        return false;
    }
    return true;
}

#endif // SENHA_CPP_INCLUDED