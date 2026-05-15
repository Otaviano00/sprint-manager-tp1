#ifndef SENHA_CPP_INCLUDED
#define SENHA_CPP_INCLUDED

#include <dominios/Senha.hpp>
#include <string>
#include <stdexcept>
#include <util/StringUtils.hpp>

using namespace std;

bool Senha::validar(string valor)
{
    if (valor.length() != 6)
    {
        throw invalid_argument("Senha deve ter exatamente 6 caracteres");
    }

    int countMaiusc = 0, countMinusc = 0, countDigito = 0;

    for (size_t i = 0; i < valor.length(); i++)
    {
        char caractere = valor[i];

        if (!StringUtils::isChar(caractere, true) && !StringUtils::isDigit(caractere))
        {
            throw invalid_argument("Senha possui caractere inválido");
        }

        // Verifica apenas se não for o último caractere
        if (i + 1 < valor.length())
        {
            if (StringUtils::isChar(caractere, true) && StringUtils::isChar(valor[i + 1], true))
            {
                throw invalid_argument("Senha não pode ter duas letras consecutivas");
            }

            if (StringUtils::isDigit(caractere) && StringUtils::isDigit(valor[i + 1]))
            {
                throw invalid_argument("Senha não pode ter dois dígitos consecutivos");
            }
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
        throw invalid_argument("Senha deve conter pelo menos uma letra maiúscula, uma minúscula e um dígito");
    }

    return true;
}

#endif // SENHA_CPP_INCLUDED