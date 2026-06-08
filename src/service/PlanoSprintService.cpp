#include <service/PlanoSprintService.hpp>
#include <service/AutenticacaoService.hpp>

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
    case S21_LISTAR_PLANOS_DE_SPRINT_ASSOCIADOS_A_PROJETO:
        return true;

    default:
        throw std::invalid_argument("Serviço desconhecido ou não pertence a Plano de Sprint");
    }
}

void PlanoSprintService::criar(PlanoSprint &planoSprint) {}
PlanoSprint PlanoSprintService::listarPorId(int id) { return PlanoSprint(); }
std::list<PlanoSprint> PlanoSprintService::listar() { return std::list<PlanoSprint>(); }
void PlanoSprintService::atualizar(PlanoSprint &planoSprint) {}
void PlanoSprintService::excluir(int id) {}
std::list<PlanoSprint> PlanoSprintService::listarPorProjeto(Projeto &projeto) { return std::list<PlanoSprint>(); }
