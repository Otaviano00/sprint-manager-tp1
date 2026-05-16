#include <stdexcept>
#include <string>
#include <vector>

#include <dominios/Papel.hpp>
#include <UnitTestBase.hpp>

using namespace std;

class TUPapel : public UnitTestBase
{
private:
    Papel *dominio;
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

const char *TUPapel::name() const
{
    return "TUPapel";
}

void TUPapel::setUp()
{
    dominio = new Papel();
}

void TUPapel::tearDown()
{
    delete dominio;
    dominio = nullptr;
}

void TUPapel::executeTests()
{
    testarValoresValidos();
    testarValoresInvalidos();
}

void TUPapel::testarValoresValidos()
{
    const vector<string> validos = {
        "DESENVOLVEDOR",
        "MESTRE_SCRUM",
        "PROPRIETARIO_DE_PRODUTO",
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

void TUPapel::testarValoresInvalidos()
{
    const vector<string> invalidos = {
        "",
        "GERENTE",
        "MESTRE",
        "PROPRIETARIO",
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

int TUPapel::run()
{
    return UnitTestBase::run();
}

int main()
{
    TUPapel teste;
    return teste.run();
}
