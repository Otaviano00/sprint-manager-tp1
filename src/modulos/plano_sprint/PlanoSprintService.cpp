#include <modulos/plano_sprint/PlanoSprintService.hpp>
#include <modulos/autenticacao/AutenticacaoService.hpp>

PlanoSprintService::PlanoSprintService()
{
    autenticacao = AutenticacaoService::getInstance();
    repository = new PlanoSprintRepository();
}

bool PlanoSprintService::autenticarPapel(ServicoEnum servico)
{
    PapelEnum papel = autenticacao->getPapel();
    switch (servico)
    {
    case S9_CRIAR_PLANO_SPRINT:
    case S11_ATUALIZAR_PLANO_SPRINT:
    case S12_EXCLUIR_PLANO_SPRINT:
        return papel == PapelEnum::MESTRE_SCRUM;
    case S10_LER_PLANO_SPRINT:
    case S10_LISTAR_PLANO_SPRINT:
    case S21_LISTAR_PLANOS_DE_SPRINT_ASSOCIADOS_A_PROJETO:
        return true;
    default:
        throw std::invalid_argument("Serviço desconhecido ou não pertence a Plano de Sprint");
    }
}

void PlanoSprintService::criar(PlanoSprint &planoSprint)
{
    if (!autenticarPapel(S9_CRIAR_PLANO_SPRINT))
        throw std::runtime_error("Acesso negado.");
    repository->save(planoSprint);
}

PlanoSprint PlanoSprintService::listarPorId(int id)
{
    if (!autenticarPapel(S10_LER_PLANO_SPRINT))
        throw std::runtime_error("Acesso negado.");
    return repository->findById(id);
}

std::list<PlanoSprint> PlanoSprintService::listar()
{
    if (!autenticarPapel(S10_LER_PLANO_SPRINT))
        throw std::runtime_error("Acesso negado.");
    auto vec = repository->findAll();
    return std::list<PlanoSprint>(vec.begin(), vec.end());
}

void PlanoSprintService::atualizar(PlanoSprint &planoSprint)
{
    if (!autenticarPapel(S11_ATUALIZAR_PLANO_SPRINT))
        throw std::runtime_error("Acesso negado.");
    repository->update(planoSprint);
}

void PlanoSprintService::excluir(int id)
{
    if (!autenticarPapel(S12_EXCLUIR_PLANO_SPRINT))
        throw std::runtime_error("Acesso negado.");
    repository->deleteById(id);
}

std::list<PlanoSprint> PlanoSprintService::listarPorProjeto(Projeto &projeto)
{

    return std::list<PlanoSprint>();
}
