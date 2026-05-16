#include <stdexcept>
#include <string>
#include <vector>

#include <dominios/Prioridade.hpp>
#include <UnitTestBase.hpp>

using namespace std;

class TUPrioridade : public UnitTestBase
{
private:
    Prioridade *dominio;
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

const char *TUPrioridade::name() const
{
    return "TUPrioridade";
}

void TUPrioridade::setUp()
{
    dominio = new Prioridade();
}

void TUPrioridade::tearDown()
{
    delete dominio;
    dominio = nullptr;
}

void TUPrioridade::executeTests()
{
    testarValoresValidos();
    testarValoresInvalidos();
}

void TUPrioridade::testarValoresValidos()
{
    const vector<string> validos = {
        "ALTA",
        "MEDIA",
        "BAIXA",
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

void TUPrioridade::testarValoresInvalidos()
{
    const vector<string> invalidos = {
        "",
        "URGENTE",
        "alta",
        "MEDIO",
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

int TUPrioridade::run()
{
    return UnitTestBase::run();
}

int main()
{
    TUPrioridade teste;
    return teste.run();
}
