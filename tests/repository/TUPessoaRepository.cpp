#include "UnitTestBase.hpp"
#include <repository/PessoaRepository.hpp>

class TUPessoaRepository : public UnitTestBase
{
private:
    PessoaRepository *repo;
    void testarCenarioCRUD();

protected:
    const char *name() const override;
    void setUp() override;
    void tearDown() override;
    void executeTests() override;

public:
    int run();
};

const char *TUPessoaRepository::name() const
{
    return "TUPessoaRepository";
}

void TUPessoaRepository::setUp()
{
    repo = new PessoaRepository();
}

void TUPessoaRepository::tearDown()
{
    delete repo;
}

void TUPessoaRepository::executeTests()
{
    testarCenarioCRUD();
}

void TUPessoaRepository::testarCenarioCRUD()
{
    Pessoa p;
    Email email;
    email.setValor("teste@email.com");
    p.setEmail(email);

    Nome nome;
    nome.setValor("Joao Teste");
    p.setNome(nome);

    Senha senha;
    senha.setValor("A1b2C3");
    p.setSenha(senha);

    // Testar Save
    if (repo->save(p))
    {
        recordSuccess("save Pessoa");

        // Testar findById
        try
        {
            Pessoa recuperada = repo->findById(p.getId());
            if (recuperada.getEmail().getValor() == p.getEmail().getValor() &&
                recuperada.getNome().getValor() == p.getNome().getValor())
            {
                recordSuccess("findById Pessoa retorna dados corretos");
            }
            else
            {
                recordFailure("findById Pessoa retornou dados inconsistentes");
            }
        }
        catch (const std::exception &ex)
        {
            recordFailure(std::string("findById falhou com excecao: ") + ex.what());
        }

        // Testar delete
        if (repo->deleteById(p.getId()))
        {
            try
            {
                repo->findById(p.getId());
                recordFailure("Pessoa deveria ter sido deletada, mas findById nao lancou excecao");
            }
            catch (const std::exception &)
            {
                recordSuccess("deleteById removeu a pessoa corretamente");
            }
        }
        else
        {
            recordFailure("deleteById retornou false");
        }
    }
    else
    {
        recordFailure("save Pessoa retornou false");
    }
}

int TUPessoaRepository::run()
{
    return UnitTestBase::run();
}

int main()
{
    TUPessoaRepository teste;
    return teste.run();
}