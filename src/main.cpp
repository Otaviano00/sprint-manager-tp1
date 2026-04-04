#include <iostream>
#include "util/util.hpp"
#include <vector>
#include "dominios/Senha.hpp"
#include <fstream>

int main()
{
    string input;
    Senha object;
    int count = 0;

    do
    {
        std::getline(std::cin, input);
        if (object.setValor(input))
        {
            cout << "Objeto: " << input << " válido" << endl;
        }
        else
        {
            cout << "Objeto: " << input << " inválido" << endl;
        }
    } while (!input.empty() && count++ < 1000);

    return 0;
}
