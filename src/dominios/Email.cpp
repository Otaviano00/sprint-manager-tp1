#ifndef EMAIL_CPP_INCLUDED
#define EMAIL_CPP_INCLUDED

#include <dominios/Email.hpp>
#include <string>
#include <vector>
#include <stdexcept>
#include <util/StringUtils.hpp>

using namespace std;

bool Email::validar(string valor)
{
    if (valor.empty())
    {
        throw invalid_argument("E-mail não pode ser vazio.");
    }

    size_t countArroba = 0;
    for (char c : valor)
    {
        if (c == '@')
        {
            countArroba++;
        }
    }

    if (countArroba != 1)
    {
        throw invalid_argument("E-mail deve conter exatamente um '@'.");
    }

    if (valor.length() > 64 + 1 + 255)
    {
        throw invalid_argument("Tamanho total excede 320 caracteres.");
    }

    vector<string> partes = StringUtils::split(valor, "@");

    if (partes.size() != 2)
    {
        throw invalid_argument("Formato esperado: local@dominio.");
    }

    string local = partes[0];
    string dominio = partes[1];

    if (local.empty() || dominio.empty())
    {
        throw invalid_argument("Parte local ou domínio não podem ser vazios.");
    }

    if (local.length() > 64)
    {
        throw invalid_argument("Parte local excede 64 caracteres.");
    }

    if (dominio.length() > 255)
    {
        throw invalid_argument("Domínio excede 255 caracteres.");
    }

    if (StringUtils::isIn(local[0], ".-") || StringUtils::isIn(local[local.length() - 1], ".-"))
    {
        throw invalid_argument("Local não pode iniciar ou terminar com '.' ou '-'.");
    }

    for (size_t i = 0; i < local.length(); i++)
    {
        char caractere = local[i];
        if (!StringUtils::isChar(caractere, false) && !StringUtils::isDigit(caractere) && !StringUtils::isIn(caractere, ".-"))
        {
            throw invalid_argument("Caractere inválido encontrado na parte local.");
        }

        if (StringUtils::isIn(caractere, ".-") && !StringUtils::isChar(local[i + 1], false) && !StringUtils::isDigit(local[i + 1]))
        {
            throw invalid_argument("Símbolos '.' ou '-' não podem ser consecutivos na parte local.");
        }
    }

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
        throw invalid_argument("Pontos consecutivos encontrados no domínio.");
    }

    for (string subdominio : subdominios)
    {
        if (subdominio.empty())
        {
            throw invalid_argument("Subdomínio não pode ser vazio.");
        }

        if (StringUtils::isIn(subdominio[0], "-") || StringUtils::isIn(subdominio[subdominio.length() - 1], "-"))
        {
            throw invalid_argument("Subdomínio não pode iniciar ou terminar com '-'.");
        }

        for (size_t i = 0; i < subdominio.length(); i++)
        {
            char caractere = subdominio[i];
            if (!StringUtils::isChar(caractere, false) && !StringUtils::isDigit(caractere) && !StringUtils::isIn(caractere, "-"))
            {
                throw invalid_argument("Caractere inválido encontrado no domínio.");
            }

            if (StringUtils::isIn(caractere, "-") && (i + 1 >= subdominio.length() || (!StringUtils::isChar(subdominio[i + 1], false) && !StringUtils::isDigit(subdominio[i + 1]))))
            {
                throw invalid_argument("Hifens não podem ser consecutivos no domínio.");
            }
        }
    }
    return true;
}

#endif // EMAIL_CPP_INCLUDED