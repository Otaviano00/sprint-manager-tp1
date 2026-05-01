#ifndef DATA_CPP_INCLUDED
#define DATA_CPP_INCLUDED

#include <dominios/Data.hpp>
#include <string>
#include <util/DateUtils.hpp>

using namespace std;

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

    int dia = stoi(valor.substr(0, 2));
    int mes = stoi(valor.substr(3, 2));
    int ano = stoi(valor.substr(6, 4));

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