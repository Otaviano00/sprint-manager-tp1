#include <stdexcept>
#include <string>
#include <vector>

#include <dominios/Tempo.hpp>
#include <UnitTestBase.hpp>

using namespace std;

class TUTempo : public UnitTestBase
{
private:
    Tempo *dominio;
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

const char *TUTempo::name() const
{
    return "TUTempo";
}

void TUTempo::setUp()
{
    dominio = new Tempo();
}

void TUTempo::tearDown()
{
    delete dominio;
    dominio = nullptr;
}

void TUTempo::executeTests()
{
    testarValoresValidos();
    testarValoresInvalidos();
}

void TUTempo::testarValoresValidos()
{
    const vector<int> validos = {1, 365, 100};

    for (int valor : validos)
    {
        try
        {
            bool resultado = dominio->setValor(valor);
            if (!resultado)
            {
                recordFailure(string("Valor valido rejeitado: ") + to_string(valor));
                continue;
            }
            if (dominio->getValor() != valor)
            {
                recordFailure(string("Valor salvo diferente do informado: ") + to_string(valor));
                continue;
            }
            recordSuccess(string("Valor valido aceito: ") + to_string(valor));
        }
        catch (invalid_argument &ex)
        {
            recordFailure(string("Valor valido gerou excecao: ") + to_string(valor) + " - " + ex.what());
        }
    }
}

void TUTempo::testarValoresInvalidos()
{
    const vector<int> invalidos = {0, 366, -1};

    for (int valor : invalidos)
    {
        try
        {
            bool resultado = dominio->setValor(valor);
            if (resultado)
            {
                recordFailure(string("Valor invalido aceito: ") + to_string(valor));
            }
            else
            {
                recordSuccess(string("Valor invalido rejeitado: ") + to_string(valor));
            }
        }
        catch (invalid_argument &)
        {
            recordSuccess(string("Valor invalido rejeitado: ") + to_string(valor));
        }
    }
}

int TUTempo::run()
{
    return UnitTestBase::run();
}

int main()
{
    TUTempo teste;
    return teste.run();
}
