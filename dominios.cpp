#ifndef DOMINIOS_CPP_INCLUDED
#define DOMINIOS_CPP_INCLUDED

#include "dominios.hpp"
#include "util.hpp"
#include <iostream>

// Código

bool Codigo::validar(string valor)
{
    if (valor.length() != 5)
    {
        return false;
    }

    int numMaiusculos = 2;
    for (int i = 0; i < numMaiusculos; i++)
    {
        if ('A' > valor[i] || 'Z' < valor[i])
        {
            return false;
        }
    }

    for (int i = numMaiusculos; i < valor.length(); i++)
    {
        if ('0' > valor[i] || '9' < valor[i])
        {
            return false;
        }
    }

    return true;
}

// Data

bool Data::validar(string valor)
{
    // Validação do formato
    if (valor.length() != 10)
    {
        return false;
    }

    if (valor[2] != '/' || valor[5] != '/')
    {
        return false;
    }

    // Validação dos dados
    int dia = std::stoi(valor.substr(0, 2));
    int mes = std::stoi(valor.substr(3, 2));
    int ano = std::stoi(valor.substr(6, 4));

    if (dia < 1 || dia > 31)
    {
        return false;
    }

    if (mes < 1 || mes > 12)
    {
        return false;
    }

    if (ano < 2000 || ano > 2999)
    {
        return false;
    }

    if (!DateUtils::isValidDate(dia, mes, ano))
    {
        return false;
    }

    return true;
}

// Tempo

bool Tempo::validar(int valor)
{
    if (valor < 1 || valor > 365)
    {
        return false;
    }
    return true;
}

// Nome

bool Nome::validar(string valor)
{
    if (valor.empty() || valor.length() > 10)
    {
        return false;
    }

    for (int i = 0; i < valor.length(); i++)
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

    for (int i = 0; i < local.length(); i++)
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
    int count = 0;

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

        for (int i = 0; i < subdominio.length(); i++)
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

// Texto

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

    for (int i = 0; i < valor.length(); i++)
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

bool Senha::validar(string valor)
{
    if (valor.length() != 6)
    {
        return false;
    }

    int countMaiusc = 0, countMinusc = 0, countDigito = 0;

    for (int i = 0; i < valor.length(); i++)
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

#endif // DOMINIOS_CPP_INCLUDED
