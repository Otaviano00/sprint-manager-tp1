#ifndef DATA_CPP_INCLUDED
#define DATA_CPP_INCLUDED

#include "Data.hpp"

bool Data::validar(string valor)
{
    if (valor.length() != 10)
    {
        throw invalid_argument("Tamanho inválido!");
    }

    if (valor[2] != '/' || valor[5] != '/')
    {
        throw invalid_argument("Formato inválido!");
    }

    int dia = std::stoi(valor.substr(0, 2));
    int mes = std::stoi(valor.substr(3, 2));
    int ano = std::stoi(valor.substr(6, 4));

    if (dia < 1 || dia > 31)
    {
        throw invalid_argument("Dia inválido!");
    }

    if (mes < 1 || mes > 12)
    {
        throw invalid_argument("Mês inválido!");
    }

    if (ano < 2000 || ano > 2999)
    {
        throw invalid_argument("Ano inválido!");
    }

    if (!DateUtils::isValidDate(dia, mes, ano))
    {
        throw invalid_argument("Data inválida!");
    }
    return true;
}

#endif // DATA_CPP_INCLUDED