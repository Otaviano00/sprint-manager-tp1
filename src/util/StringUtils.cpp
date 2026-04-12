#ifndef STRING_UTILS_CPP_INCLUDED
#define STRING_UTILS_CPP_INCLUDED

#include "StringUtils.hpp"

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

#endif // STRING_UTILS_CPP_INCLUDED