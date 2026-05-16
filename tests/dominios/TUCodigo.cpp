#include <stdexcept>
#include <string>
#include <vector>

#include <dominios/Codigo.hpp>
#include <UnitTestBase.hpp>

using namespace std;

class TUCodigo : public UnitTestBase
{
private:
    Codigo *dominio;
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

const char *TUCodigo::name() const
{
    return "TUCodigo";
}

void TUCodigo::setUp()
{
    dominio = new Codigo();
}

void TUCodigo::tearDown()
{
    delete dominio;
    dominio = nullptr;
}

void TUCodigo::executeTests()
{
    testarValoresValidos();
    testarValoresInvalidos();
}

void TUCodigo::testarValoresValidos()
{
    const vector<string> validos = {
        "AB123",
        "ZZ999",
        "AA000",
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

void TUCodigo::testarValoresInvalidos()
{
    const vector<string> invalidos = {
        "AB12",
        "AB1234",
        "Ab123",
        "aB123",
        "ABC12",
        "AB12C",
        "12ABC",
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

int TUCodigo::run()
{
    return UnitTestBase::run();
}

int main()
{
    TUCodigo teste;
    return teste.run();
}
