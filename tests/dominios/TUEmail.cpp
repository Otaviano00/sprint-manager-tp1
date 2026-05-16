#include <stdexcept>
#include <string>
#include <vector>

#include <dominios/Email.hpp>
#include <UnitTestBase.hpp>

using namespace std;

class TUEmail : public UnitTestBase
{
private:
    Email *dominio;
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

const char *TUEmail::name() const
{
    return "TUEmail";
}

void TUEmail::setUp()
{
    dominio = new Email();
}

void TUEmail::tearDown()
{
    delete dominio;
    dominio = nullptr;
}

void TUEmail::executeTests()
{
    testarValoresValidos();
    testarValoresInvalidos();
}

void TUEmail::testarValoresValidos()
{
    const vector<string> validos = {
        "ana.silva-1@exemplo.com",
        "a1@sub-dominio.exemplo.com",
        "abc-def.ghi@exemplo",
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

void TUEmail::testarValoresInvalidos()
{
    vector<string> invalidos = {
        "",
        "ana.exemplo.com",
        "ana@@exemplo.com",
        "@exemplo.com",
        "ana@",
        ".ana@exemplo.com",
        "ana-@exemplo.com",
        "ana..silva@exemplo.com",
        "ana.-silva@exemplo.com",
        "ana_silva@exemplo.com",
        "ana@-exemplo.com",
        "ana@exemplo-.com",
        "ana@ex..com",
    };

    invalidos.push_back(string(65, 'a') + "@exemplo.com");
    invalidos.push_back(string("a@") + string(256, 'a'));

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

int TUEmail::run()
{
    return UnitTestBase::run();
}

int main()
{
    TUEmail teste;
    return teste.run();
}
