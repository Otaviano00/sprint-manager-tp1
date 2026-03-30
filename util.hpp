#ifndef UTIL_HPP_INCLUDED
#define UTIL_HPP_INCLUDED

// Dominíos - Útil

#include <iostream>
#include <vector>

using namespace std;

enum Mes
{
    JANEIRO = 1,
    FEVEREIRO = 2,
    MARCO = 3,
    ABRIL = 4,
    MAIO = 5,
    JUNHO = 6,
    JULHO = 7,
    AGOSTO = 8,
    SETEMBRO = 9,
    OUTUBRO = 10,
    NOVEMBRO = 11,
    DEZEMBRO = 12
};

class StringUtils
{
public:
    static bool isChar(char caracter, bool includeCaps);
    static bool isDigit(char caracter);
    static bool isIn(char caracter, string values);
    static vector<string> split(const string value, const string delimiter);
};

class DateUtils
{
public:
    static bool isAnoBissexto(int year);
    static bool isValidDate(int day, int month, int year);
};

#endif // UTIL_HPP_INCLUDED