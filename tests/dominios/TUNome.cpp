#include <stdexcept>
#include <string>
#include <vector>

#include <dominios/Nome.hpp>
#include <UnitTestBase.hpp>

using namespace std;

class TUNome : public UnitTestBase
{
private:
    Nome *dominio;
    void testarValoresValidos();
    void testarValoresInvalidos();

protected:
    const char *name() const override;
    void setUp() override;
    void tearDown() override;
    void executeTests() override;

public:
    int run();
};

const char *TUNome::name() const
{
    return "TUNome";
}

void TUNome::setUp()
{
    dominio = new Nome();
}

void TUNome::tearDown()
{
    delete dominio;
    dominio = nullptr;
}

void TUNome::executeTests()
{
    testarValoresValidos();
    testarValoresInvalidos();
}

void TUNome::testarValoresValidos()
{
    const vector<string> validos = {
        "Ana",
        "Ana Maria",
        "ABCDEFGHIJ",
        "A B",
    };

    for (const auto &valor : validos)
    {
        try
        {
            bool resultado = dominio->setValor(valor);
            if (!resultado)
            {
                recordFailure(string("Valor valido rejeitado: ") + valor);
                continue;
            }
            if (dominio->getValor() != valor)
            {
                recordFailure(string("Valor salvo diferente do informado: ") + valor);
                continue;
            }
            recordSuccess(string("Valor valido aceito: ") + valor);
        }
        catch (invalid_argument &ex)
        {
            recordFailure(string("Valor valido gerou excecao: ") + valor + " - " + ex.what());
        }
    }
}

void TUNome::testarValoresInvalidos()
{
    const vector<string> invalidos = {
        "",
        "ABCDEFGHIJK",
        " Ana",
        "Ana ",
        "Ana  Maria",
        "Ana1",
        "Ana-",
    };

    for (const auto &valor : invalidos)
    {
        try
        {
            bool resultado = dominio->setValor(valor);
            if (resultado)
            {
                recordFailure(string("Valor invalido aceito: ") + valor);
            }
            else
            {
                recordSuccess(string("Valor invalido rejeitado: ") + valor);
            }
        }
        catch (invalid_argument &)
        {
            recordSuccess(string("Valor invalido rejeitado: ") + valor);
        }
    }
}

int TUNome::run()
{
    return UnitTestBase::run();
}

int main()
{
    TUNome teste;
    return teste.run();
}
