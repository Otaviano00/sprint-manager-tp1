#include <stdexcept>
#include <string>
#include <vector>

#include <dominios/Data.hpp>
#include <UnitTestBase.hpp>

using namespace std;

class TUData : public UnitTestBase
{
private:
    Data *dominio;
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

const char *TUData::name() const
{
    return "TUData";
}

void TUData::setUp()
{
    dominio = new Data();
}

void TUData::tearDown()
{
    delete dominio;
    dominio = nullptr;
}

void TUData::executeTests()
{
    testarValoresValidos();
    testarValoresInvalidos();
}

void TUData::testarValoresValidos()
{
    const vector<string> validos = {
        "01/01/2000",
        "29/02/2024",
        "31/12/2999",
        "30/04/2026",
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

void TUData::testarValoresInvalidos()
{
    const vector<string> invalidos = {
        "",
        "1/01/2024",
        "01-01-2024",
        "32/01/2024",
        "00/01/2024",
        "01/13/2024",
        "01/00/2024",
        "01/01/1999",
        "01/01/3000",
        "29/02/2023",
        "31/04/2026",
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

int TUData::run()
{
    return UnitTestBase::run();
}

int main()
{
    TUData teste;
    return teste.run();
}
