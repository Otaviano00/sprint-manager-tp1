#include "UnitTestBase.hpp"
#include <modulos/historia_usuario/HistoriaDeUsuarioRepository.hpp>

class TUHistoriaDeUsuarioRepository : public UnitTestBase
{
private:
    HistoriaDeUsuarioRepository *repo;
    void testarCenarioCRUD();

protected:
    const char *name() const override;
    void setUp() override;
    void tearDown() override;
    void executeTests() override;

public:
    int run();
};

const char *TUHistoriaDeUsuarioRepository::name() const
{
    return "TUHistoriaDeUsuarioRepository";
}

void TUHistoriaDeUsuarioRepository::setUp()
{
    repo = new HistoriaDeUsuarioRepository();
}

void TUHistoriaDeUsuarioRepository::tearDown()
{
    delete repo;
}

void TUHistoriaDeUsuarioRepository::executeTests()
{
    testarCenarioCRUD();
}

void TUHistoriaDeUsuarioRepository::testarCenarioCRUD()
{
    HistoriaDeUsuario hu;

    Codigo codigo;
    codigo.setValor("HI123");
    hu.setCodigo(codigo);

    Texto titulo;
    titulo.setValor("Como usuario quero testar titulo");
    hu.setTitulo(titulo);

    Texto papel;
    papel.setValor("Desenvolvedor");
    hu.setPapel(papel);

    Texto acao;
    acao.setValor("Criar teste do repositorio");
    hu.setAcao(acao);

    Texto valor;
    valor.setValor("Garantir estabilidade");
    hu.setValor(valor);

    Tempo estimativa;
    estimativa.setValor(5);
    hu.setEstimativa(estimativa);

    Prioridade prioridade;
    prioridade.setValor("ALTA");
    hu.setPrioridade(prioridade);

    Estado estado;
    estado.setValor("A FAZER");
    hu.setEstado(estado);

    if (repo->save(hu))
    {
        recordSuccess("save HistoriaDeUsuario");

        try
        {
            HistoriaDeUsuario recuperada = repo->findById(hu.getId());
            if (recuperada.getCodigo().getValor() == hu.getCodigo().getValor() &&
                recuperada.getTitulo().getValor() == hu.getTitulo().getValor())
            {
                recordSuccess("findById HistoriaDeUsuario retorna dados corretos");
            }
            else
            {
                recordFailure("findById HistoriaDeUsuario retornou dados inconsistentes");
            }
        }
        catch (const std::exception &ex)
        {
            recordFailure(std::string("findById falhou com excecao: ") + ex.what());
        }

        if (repo->deleteById(hu.getId()))
        {
            try
            {
                repo->findById(hu.getId());
                recordFailure("HistoriaDeUsuario deveria ter sido deletada, mas findById nao lancou excecao");
            }
            catch (const std::exception &)
            {
                recordSuccess("deleteById removeu a HistoriaDeUsuario corretamente");
            }
        }
        else
        {
            recordFailure("deleteById retornou false");
        }
    }
    else
    {
        recordFailure("save HistoriaDeUsuario retornou false");
    }
}

int TUHistoriaDeUsuarioRepository::run()
{
    return UnitTestBase::run();
}

int main()
{
    TUHistoriaDeUsuarioRepository teste;
    return teste.run();
}