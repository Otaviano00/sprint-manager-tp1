#ifndef UTIL_CPP_INCLUDED
#define UTIL_CPP_INCLUDED

#include "util.hpp"
#include <iostream>
#include <vector>

using namespace std;
// StringUtils

bool StringUtils::isChar(char caracter, bool includeCaps)
{
    if (
        (caracter >= 'a' && caracter <= 'z') ||
        (includeCaps &&
         (caracter >= 'A' && caracter <= 'Z')))
    {
        return true;
    }
    return false;
}

bool StringUtils::isDigit(char caracter)
{
    if (caracter >= '0' && caracter <= '9')
    {
        return true;
    }
    return false;
}

bool StringUtils::isIn(char caracter, string values)
{
    for (char value : values)
    {
        if (caracter == value)
        {
            return true;
        }
    }
    return false;
}

vector<string> StringUtils::split(const string value, const string delimiter)
{
    vector<string> values;
    size_t start = 0;
    size_t end = value.find(delimiter);

    while (end != string::npos)
    {
        string token = value.substr(start, end - start);
        if (!token.empty())
        {
            values.push_back(token);
        }
        start = end + delimiter.length();
        end = value.find(delimiter, start);
    }

    string last_token = value.substr(start);
    if (!last_token.empty())
    {
        values.push_back(last_token);
    }

    return values;
}

// DateUtils

bool DateUtils::isAnoBissexto(int year)
{
    // if: year é divisível por 4 e year é divisível por 100 ou year é divisível por 400, então year é bissexto
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    return false;
}

// Não valida corretamente anos A.C
bool DateUtils::isValidDate(int day, int month, int year)
{
    if (month < 1 || month > 12 || day < 1)
    {
        return false;
    }

    switch (static_cast<Mes>(month))
    {
    case Mes::FEVEREIRO:
        return isAnoBissexto(year) ? day <= 29 : day <= 28;

    case Mes::JANEIRO:
    case Mes::MARCO:
    case Mes::MAIO:
    case Mes::JULHO:
    case Mes::AGOSTO:
    case Mes::OUTUBRO:
    case Mes::DEZEMBRO:
        return day <= 31;

    case Mes::ABRIL:
    case Mes::JUNHO:
    case Mes::SETEMBRO:
    case Mes::NOVEMBRO:
        return day <= 30;
    default:
        return false;
    }
}

#endif