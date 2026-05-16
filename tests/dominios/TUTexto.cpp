#include <stdexcept>
#include <string>
#include <vector>

#include <dominios/Texto.hpp>
#include <UnitTestBase.hpp>

using namespace std;

class TUTexto : public UnitTestBase
{
private:
    Texto *dominio;
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

const char *TUTexto::name() const
{
    return "TUTexto";
}

void TUTexto::setUp()
{
    dominio = new Texto();
}

void TUTexto::tearDown()
{
    delete dominio;
    dominio = nullptr;
}

void TUTexto::executeTests()
{
    testarValoresValidos();
    testarValoresInvalidos();
}

void TUTexto::testarValoresValidos()
{
    const vector<string> validos = {
        "Texto 1, versao 2",
        "Oi, tudo bem 123",
        "A 1, B 2. C 3",
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

void TUTexto::testarValoresInvalidos()
{
    vector<string> invalidos = {
        " Texto",
        "Texto ",
        ".Texto",
        "Texto,",
        "Texto..invalido",
        "Oi,,tudo",
        "Oi,.tudo",
        "Oi.,tudo",
        "Oi  tudo",
        "Oi ,tudo",
        "Oi .tudo",
        "Oi@tudo",
    };

    invalidos.push_back(string(41, 'a'));

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

int TUTexto::run()
{
    return UnitTestBase::run();
}

int main()
{
    TUTexto teste;
    return teste.run();
}
