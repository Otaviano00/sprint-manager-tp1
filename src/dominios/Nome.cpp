#ifndef NOME_CPP_INCLUDED
#define NOME_CPP_INCLUDED

#include <dominios/Nome.hpp>
#include <string>
#include <util/StringUtils.hpp>

using namespace std;

bool Nome::validar(string valor)
{
    if (valor.empty() || valor.length() > 10)
    {
        return false;
    }

    for (size_t i = 0; i < valor.length(); i++)
    {
        char caracter = valor[i];
        if (!StringUtils::isChar(caracter, true) && !StringUtils::isIn(caracter, " "))
        {
            return false;
        }

        if (StringUtils::isIn(caracter, " ") && (i + 1 >= valor.length() || !StringUtils::isChar(valor[i + 1], true)))
        {
            return false;
        }
    }

    if (StringUtils::isIn(valor[0], " ") || StringUtils::isIn(valor[valor.length() - 1], " "))
    {
        return false;
    }

    return true;
}

#endif // NOME_CPP_INCLUDED