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
        return false;
    }

    if (valor[2] != '/' || valor[5] != '/')
    {
        return false;
    }

    int dia = stoi(valor.substr(0, 2));
    int mes = stoi(valor.substr(3, 2));
    int ano = stoi(valor.substr(6, 4));

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

#endif // DATA_CPP_INCLUDED