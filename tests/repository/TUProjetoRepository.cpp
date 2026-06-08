#include "UnitTestBase.hpp"
#include <modulos/projeto/ProjetoRepository.hpp>

class TUProjetoRepository : public UnitTestBase
{
private:
    ProjetoRepository *repo;
    void testarCenarioCRUD();

protected:
    const char *name() const override;
    void setUp() override;
    void tearDown() override;
    void executeTests() override;

public:
    int run();
};

const char *TUProjetoRepository::name() const
{
    return "TUProjetoRepository";
}

void TUProjetoRepository::setUp()
{
    repo = new ProjetoRepository();
}

void TUProjetoRepository::tearDown()
{
    delete repo;
}

void TUProjetoRepository::executeTests()
{
    testarCenarioCRUD();
}

void TUProjetoRepository::testarCenarioCRUD()
{
    Projeto p;
    Codigo codigo;
    codigo.setValor("PR123");
    p.setCodigo(codigo);

    Nome nome;
    nome.setValor("Proj Teste");
    p.setNome(nome);

    Data dataInicio;
    dataInicio.setValor("10/10/2030");
    p.setDataInicio(dataInicio);

    Data dataFim;
    dataFim.setValor("12/10/2030");
    p.setDataFim(dataFim);

    // Testar Save
    if (repo->save(p))
    {
        recordSuccess("save Projeto");

        // Testar findById
        try
        {
            Projeto recuperada = repo->findById(p.getId());
            if (recuperada.getCodigo().getValor() == p.getCodigo().getValor() &&
                recuperada.getNome().getValor() == p.getNome().getValor())
            {
                recordSuccess("findById Projeto retorna dados corretos");
            }
            else
            {
                recordFailure("findById Projeto retornou dados inconsistentes");
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
                recordFailure("Projeto deveria ter sido deletado, mas findById nao lancou excecao");
            }
            catch (const std::exception &)
            {
                recordSuccess("deleteById removeu o projeto corretamente");
            }
        }
        else
        {
            recordFailure("deleteById retornou false");
        }
    }
    else
    {
        recordFailure("save Projeto retornou false");
    }
}

int TUProjetoRepository::run()
{
    return UnitTestBase::run();
}

int main()
{
    TUProjetoRepository teste;
    return teste.run();
}