#ifndef EMAIL_CPP_INCLUDED
#define EMAIL_CPP_INCLUDED

#include <dominios/Email.hpp>
#include <string>
#include <vector>
#include <util/StringUtils.hpp>

using namespace std;

bool Email::validar(string valor)
{
    if (valor.length() > 64 + 1 + 255)
    {
        return false;
    }

    vector<string> partes = StringUtils::split(valor, "@");

    if (partes.size() != 2)
    {
        return false;
    }

    string local = partes[0];

    if (StringUtils::isIn(local[0], ".-") || StringUtils::isIn(local[local.length() - 1], ".-"))
    {
        return false;
    }

    for (size_t i = 0; i < local.length(); i++)
    {
        char caractere = local[i];
        if (!StringUtils::isChar(caractere, false) && !StringUtils::isDigit(caractere) && !StringUtils::isIn(caractere, ".-"))
        {
            return false;
        }

        if (StringUtils::isIn(caractere, ".-") && !StringUtils::isChar(local[i + 1], false) && !StringUtils::isDigit(local[i + 1]))
        {
            return false;
        }
    }

    string dominio = partes[1];
    size_t count = 0;

    for (char caractere : dominio)
    {
        if (caractere == '.')
        {
            count++;
        }
    }

    vector<string> subdominios = StringUtils::split(dominio, ".");
    if (count + 1 != subdominios.size())
    {
        return false;
    }

    for (string subdominio : subdominios)
    {
        if (StringUtils::isIn(subdominio[0], "-") || StringUtils::isIn(subdominio[subdominio.length() - 1], "-"))
        {
            return false;
        }

        for (size_t i = 0; i < subdominio.length(); i++)
        {
            char caractere = subdominio[i];
            if (!StringUtils::isChar(caractere, false) && !StringUtils::isDigit(caractere) && !StringUtils::isIn(caractere, "-"))
            {
                return false;
            }

            if (StringUtils::isIn(caractere, "-") && !StringUtils::isChar(subdominio[i + 1], false) && !StringUtils::isDigit(subdominio[i + 1]))
            {
                return false;
            }
        }
    }

    return true;
}

#endif // EMAIL_CPP_INCLUDED