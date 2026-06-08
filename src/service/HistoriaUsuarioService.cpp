#include <service/HistoriaUsuarioService.hpp>
#include <service/AutenticacaoService.hpp>

HistoriaUsuarioService::HistoriaUsuarioService()
{
    autenticacao = AutenticacaoService::getInstance();
    repository = new HistoriaDeUsuarioRepository();
}

bool HistoriaUsuarioService::autenticarPapel(ServicoEnum servico)
{
    PapelEnum papel = autenticacao->getPapel();

    switch (servico)
    {
    case S13_CRIAR_HISTORIA_USUARIO:
    case S15_ATUALIZAR_HISTORIA_USUARIO:
    case S16_EXCLUIR_HISTORIA_USUARIO:
        return papel == PapelEnum::PROPRIETARIO_DE_PRODUTO;

    case S17_ESTABELECER_ASSOCIACAO_ENTRE_HU_E_PESSOA:
    case S18_REMOVER_ASSOCIACAO_ENTRE_HU_E_PESSOA:
    case S24_MOVER_HU_DE_PROJETO_PARA_PLANO_SPRINT:
        return papel == PapelEnum::MESTRE_SCRUM;

    case S25_ALTERAR_ESTADO_DE_HISTORIA_USUARIO:
        return (papel == PapelEnum::PROPRIETARIO_DE_PRODUTO || papel == PapelEnum::MESTRE_SCRUM);

    case S14_LER_HISTORIA_USUARIO:
    case S20_LISTAR_HU_ASSOCIADAS_A_PROJETO:
    case S22_LISTAR_HU_ASSOCIADAS_A_PLANO_SPRINT:
    case S23_LISTAR_HU_ASSOCIADAS_A_PESSOA:
        return true;

    default:
        throw std::invalid_argument("Serviço desconhecido ou não pertence a História de Usuário");
    }
}

void HistoriaUsuarioService::criar(HistoriaDeUsuario &historiaUsuario) {}
HistoriaDeUsuario HistoriaUsuarioService::listarPorId(int id) { return HistoriaDeUsuario(); }
std::list<HistoriaDeUsuario> HistoriaUsuarioService::listar() { return std::list<HistoriaDeUsuario>(); }
void HistoriaUsuarioService::atualizar(HistoriaDeUsuario &historiaUsuario) {}
void HistoriaUsuarioService::excluir(int id) {}
void HistoriaUsuarioService::alterarEstado(std::string estado) {}
void HistoriaUsuarioService::vincularPessoa(Pessoa &pessoa) {}
void HistoriaUsuarioService::desvincularPessoa(Pessoa &pessoa) {}
std::list<HistoriaDeUsuario> HistoriaUsuarioService::listarPorProjeto(Projeto &projeto) { return std::list<HistoriaDeUsuario>(); }
std::list<HistoriaDeUsuario> HistoriaUsuarioService::listarPorPlanoSprint(PlanoSprint &planoSprint) { return std::list<HistoriaDeUsuario>(); }
std::list<HistoriaDeUsuario> HistoriaUsuarioService::listarPorPessoa(Pessoa &pessoa) { return std::list<HistoriaDeUsuario>(); }
void HistoriaUsuarioService::moverParaSprint(PlanoSprint &planoSprint) {}
