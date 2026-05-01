#ifndef TEXTO_CPP_INCLUDED
#define TEXTO_CPP_INCLUDED

#include <dominios/Texto.hpp>
#include <string>
#include <stdexcept>
#include <util/StringUtils.hpp>

using namespace std;

bool Texto::validar(string valor)
{
    if (valor.length() > 40)
    {
        throw invalid_argument("Texto com mais de 40 caracteres");
    }

    if (StringUtils::isIn(valor[0], ",. ") || 
        StringUtils::isIn(valor[valor.length() - 1], ",. "))
    {
        throw invalid_argument("Texto não pode começar ou terminar com pontuação ou espaço");
    }

    for (size_t i = 0; i < valor.length(); i++)
    {
        char caractere = valor[i];
        bool isChar = StringUtils::isChar(caractere, true);
        bool isDigit = StringUtils::isDigit(caractere);
        bool isIn = StringUtils::isIn(caractere, ",. ");

        if (!isChar && !isDigit && !isIn)
        {
            throw invalid_argument("Caractere inválido no texto");
        }

        // Verifica apenas se não for o último caractere
        if (i + 1 < valor.length())
        {
            if (StringUtils::isIn(caractere, ",.") && 
                StringUtils::isIn(valor[i + 1], ",."))
            {
                throw invalid_argument("Pontuação duplicada");
            }

            if (caractere == ' ' && 
                !StringUtils::isChar(valor[i + 1], true) && 
                !StringUtils::isDigit(valor[i + 1]))
            {
                throw invalid_argument("Espaço em posição inválida");
            }
        }
    }

    return true;
}

#endif // TEXTO_CPP_INCLUDED