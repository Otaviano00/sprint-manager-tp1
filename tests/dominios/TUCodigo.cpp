#include <stdexcept>
#include <dominios/Codigo.hpp>
#include <iostream>

class TUCodigo {
private:
    Codigo *codigo;
    int estado;
    void setUp();
    void tearDown();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();

};

int main() {
    std::cout << "Teste de Unidade - Codigo" << std::endl;
    return TUCodigo::SUCESSO;
}
