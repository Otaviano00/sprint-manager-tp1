#include <stdexcept>
#include <string>
#include <vector>

#include <dominios/Estado.hpp>
#include <UnitTestBase.hpp>

using namespace std;

class TUEstado : public UnitTestBase
{
private:
    Estado *dominio;
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

const char *TUEstado::name() const
{
    return "TUEstado";
}

void TUEstado::setUp()
{
    dominio = new Estado();
}

void TUEstado::tearDown()
{
    delete dominio;
    dominio = nullptr;
}

void TUEstado::executeTests()
{
    testarValoresValidos();
    testarValoresInvalidos();
}

void TUEstado::testarValoresValidos()
{
    const vector<string> validos = {
        "A FAZER",
        "FAZENDO",
        "FEITO",
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

void TUEstado::testarValoresInvalidos()
{
    const vector<string> invalidos = {
        "",
        "DONE",
        "A_FAZER_",
        "AFAZER",
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

int TUEstado::run()
{
    return UnitTestBase::run();
}

int main()
{
    TUEstado teste;
    return teste.run();
}
