#include <stdexcept>
#include <string>
#include <vector>

#include <dominios/Senha.hpp>
#include <UnitTestBase.hpp>

using namespace std;

class TUSenha : public UnitTestBase
{
private:
    Senha *dominio;
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

const char *TUSenha::name() const
{
    return "TUSenha";
}

void TUSenha::setUp()
{
    dominio = new Senha();
}

void TUSenha::tearDown()
{
    delete dominio;
    dominio = nullptr;
}

void TUSenha::executeTests()
{
    testarValoresValidos();
    testarValoresInvalidos();
}

void TUSenha::testarValoresValidos()
{
    const vector<string> validos = {
        "A1b2C3",
        "a1B2c3",
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

void TUSenha::testarValoresInvalidos()
{
    const vector<string> invalidos = {
        "A1b2C",
        "A1b2C34",
        "A12bC3",
        "AB1c2D",
        "A1B2C3",
        "a1b2c3",
        "Aa1b2C",
        "A1b!C3",
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

int TUSenha::run()
{
    return UnitTestBase::run();
}

int main()
{
    TUSenha teste;
    return teste.run();
}
