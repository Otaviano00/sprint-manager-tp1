#include "UnitTestBase.hpp"
#include <repository/PlanoSprintRepository.hpp>

class TUPlanoSprintRepository : public UnitTestBase
{
private:
    PlanoSprintRepository *repo;
    void testarCenarioCRUD();

protected:
    const char *name() const override;
    void setUp() override;
    void tearDown() override;
    void executeTests() override;

public:
    int run();
};

const char *TUPlanoSprintRepository::name() const
{
    return "TUPlanoSprintRepository";
}

void TUPlanoSprintRepository::setUp()
{
    repo = new PlanoSprintRepository();
}

void TUPlanoSprintRepository::tearDown()
{
    delete repo;
}

void TUPlanoSprintRepository::executeTests()
{
    testarCenarioCRUD();
}

void TUPlanoSprintRepository::testarCenarioCRUD()
{
    PlanoSprint ps;
    Codigo codigo;
    codigo.setValor("SP123");
    ps.setCodigo(codigo);

    Nome nome;
    nome.setValor("Spt Teste");
    ps.setNome(nome);

    Data dataInicio;
    dataInicio.setValor("01/01/2030");
    ps.setDataInicio(dataInicio);

    Data dataFim;
    dataFim.setValor("10/01/2030");
    ps.setDataFim(dataFim);

    if (repo->save(ps))
    {
        recordSuccess("save PlanoSprint");

        try
        {
            PlanoSprint recuperada = repo->findById(ps.getId());
            if (recuperada.getCodigo().getValor() == ps.getCodigo().getValor() &&
                recuperada.getNome().getValor() == ps.getNome().getValor())
            {
                recordSuccess("findById PlanoSprint retorna dados corretos");
            }
            else
            {
                recordFailure("findById PlanoSprint retornou dados inconsistentes");
            }
        }
        catch (const std::exception &ex)
        {
            recordFailure(std::string("findById falhou com excecao: ") + ex.what());
        }

        if (repo->deleteById(ps.getId()))
        {
            try
            {
                repo->findById(ps.getId());
                recordFailure("PlanoSprint deveria ter sido deletado, mas findById nao lancou excecao");
            }
            catch (const std::exception &)
            {
                recordSuccess("deleteById removeu o PlanoSprint corretamente");
            }
        }
        else
        {
            recordFailure("deleteById retornou false");
        }
    }
    else
    {
        recordFailure("save PlanoSprint retornou false");
    }
}

int TUPlanoSprintRepository::run()
{
    return UnitTestBase::run();
}

int main()
{
    TUPlanoSprintRepository teste;
    return teste.run();
}