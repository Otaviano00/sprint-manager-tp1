#ifndef DATE_UTILS_CPP_INCLUDED
#define DATE_UTILS_CPP_INCLUDED

#include "DateUtils.hpp"

bool DateUtils::isAnoBissexto(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    return false;
}

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

#endif // DATE_UTILS_CPP_INCLUDED