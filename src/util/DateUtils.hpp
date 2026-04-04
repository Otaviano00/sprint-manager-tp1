#ifndef DATE_UTILS_HPP_INCLUDED
#define DATE_UTILS_HPP_INCLUDED

#include "../dominios/Mes.hpp"

class DateUtils
{
public:
    static bool isAnoBissexto(int year);
    static bool isValidDate(int day, int month, int year);
};

#endif // DATE_UTILS_HPP_INCLUDED