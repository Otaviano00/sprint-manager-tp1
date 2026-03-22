#include <iostream>
#include"dominios.hpp"

using namespace std;

int main()
{
    string input =  "Teste";
    Nome nome;

    if (nome.setValor(input)) {
        cout << input << " é válido" << endl;
    } else {
        cout << input << " não é válido" << endl;
    }

    return 0;
}
