#ifndef STRING_UTILS_HPP_INCLUDED
#define STRING_UTILS_HPP_INCLUDED

using namespace std;
#include <string>
#include <vector>

class StringUtils
{
public:
    static bool isChar(char caracter, bool includeCaps);
    static bool isDigit(char caracter);
    static bool isIn(char caracter, string values);
    static vector<string> split(const string value, const string delimiter);
};

#endif // STRING_UTILS_HPP_INCLUDED