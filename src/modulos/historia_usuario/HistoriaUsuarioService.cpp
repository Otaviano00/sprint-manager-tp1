#include <modulos/historia_usuario/HistoriaUsuarioService.hpp>
#include <modulos/autenticacao/AutenticacaoService.hpp>
#include <stdexcept>
#include <string>
#include <ctime>

// Helper para calcular diff entre datas no formato DD/MM/AAAA
static int diffDias(const std::string &data1, const std::string &data2)
{
    std::tm tm1 = {};
    std::tm tm2 = {};

    sscanf(data1.c_str(), "%d/%d/%d", &tm1.tm_mday, &tm1.tm_mon, &tm1.tm_year);
    sscanf(data2.c_str(), "%d/%d/%d", &tm2.tm_mday, &tm2.tm_mon, &tm2.tm_year);

    tm1.tm_mon -= 1;
    tm1.tm_year -= 1900;
    tm2.tm_mon -= 1;
    tm2.tm_year -= 1900;

    std::time_t t1 = std::mktime(&tm1);
    std::time_t t2 = std::mktime(&tm2);

    double seconds = std::difftime(t2, t1);
    return std::max(0, static_cast<int>(seconds / (60 * 60 * 24)));
}

HistoriaUsuarioService::HistoriaUsuarioService()
{
    autenticacao = AutenticacaoService::getInstance();
    repository = new HistoriaDeUsuarioRepository();
    planoSprintRepository = new PlanoSprintRepository();
    pessoaRepository = new PessoaRepository();
}

HistoriaUsuarioService::~HistoriaUsuarioService()
{
    delete repository;
    delete planoSprintRepository;
    delete pessoaRepository;
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
        return (papel == PapelEnum::PROPRIETARIO_DE_PRODUTO || papel == PapelEnum::MESTRE_SCRUM || papel == PapelEnum::DESENVOLVEDOR);

    case S14_LER_HISTORIA_USUARIO:
    case S14_LISTAR_HISTORIA_USUARIO:
    case S20_LISTAR_HU_ASSOCIADAS_A_PROJETO:
    case S22_LISTAR_HU_ASSOCIADAS_A_PLANO_SPRINT:
    case S23_LISTAR_HU_ASSOCIADAS_A_PESSOA:
        return true;

    default:
        throw std::invalid_argument("Servico desconhecido");
    }
}

void HistoriaUsuarioService::criar(HistoriaDeUsuario &historiaUsuario)
{
    if (!autenticarPapel(S13_CRIAR_HISTORIA_USUARIO))
        throw std::invalid_argument("Acesso negado: Somente o PROPRIETARIO DE PRODUTO pode criar historia.");

    if (historiaUsuario.getProjeto().getId() == 0)
    {
        throw std::invalid_argument("A historia de usuario deve estar associada a um Projeto na criacao.");
    }

    Estado estadoInicial;
    estadoInicial.setValor("A FAZER");
    historiaUsuario.setEstado(estadoInicial);

    if (!repository->save(historiaUsuario))
        throw std::runtime_error("Erro ao salvar a historia de usuario.");
}

HistoriaDeUsuario HistoriaUsuarioService::listarPorId(int id)
{
    if (!autenticarPapel(S14_LER_HISTORIA_USUARIO))
        throw std::invalid_argument("Acesso negado.");

    return repository->findById(id);
}

std::list<HistoriaDeUsuario> HistoriaUsuarioService::listar()
{
    if (!autenticarPapel(S14_LER_HISTORIA_USUARIO))
        throw std::invalid_argument("Acesso negado.");

    auto vec = repository->findAll();
    return std::list<HistoriaDeUsuario>(vec.begin(), vec.end());
}

void HistoriaUsuarioService::atualizar(HistoriaDeUsuario &historiaUsuario)
{
    if (!autenticarPapel(S15_ATUALIZAR_HISTORIA_USUARIO))
        throw std::invalid_argument("Acesso negado.");

    if (!repository->update(historiaUsuario))
        throw std::runtime_error("Erro ao atualizar.");
}

void HistoriaUsuarioService::excluir(int id)
{
    if (!autenticarPapel(S16_EXCLUIR_HISTORIA_USUARIO))
        throw std::invalid_argument("Acesso negado.");

    HistoriaDeUsuario historia = repository->findById(id);
    std::string estado = historia.getEstado().getValor();

    if (estado != "A FAZER" && estado != "FEITO")
    {
        throw std::invalid_argument("Apenas historias 'A FAZER' ou 'FEITO' podem ser excluidas.");
    }

    if (!repository->deleteById(id))
        throw std::runtime_error("Erro ao excluir historia de usuario.");
}

void HistoriaUsuarioService::alterarEstado(int historiaId, std::string novoEstadoRegistro)
{
    if (!autenticarPapel(S25_ALTERAR_ESTADO_DE_HISTORIA_USUARIO))
        throw std::invalid_argument("Acesso negado: Voce nao tem permissao para alterar estado da HU.");

    PapelEnum papel = autenticacao->getPapel();
    if (papel == PapelEnum::DESENVOLVEDOR && novoEstadoRegistro != "FAZENDO" && novoEstadoRegistro != "FEITO")
    {
        throw std::invalid_argument("Desenvolvedor so pode alterar o estado para FAZENDO ou FEITO.");
    }

    HistoriaDeUsuario historia = repository->findById(historiaId);
    Estado estado;
    estado.setValor(novoEstadoRegistro);
    historia.setEstado(estado);

    if (!repository->update(historia))
        throw std::runtime_error("Erro ao atualizar o estado.");
}

void HistoriaUsuarioService::vincularPessoa(int historiaId, Pessoa &pessoa)
{
    if (!autenticarPapel(S17_ESTABELECER_ASSOCIACAO_ENTRE_HU_E_PESSOA))
        throw std::invalid_argument("Acesso negado: Somente MESTRE SCRUM pode associar pessoa.");

    Pessoa pessoaComSessao = pessoaRepository->findById(pessoa.getId());
    if (pessoaComSessao.getPapel().getValor() != "DESENVOLVEDOR")
    {
        throw std::invalid_argument("So e possivel associar um DESENVOLVEDOR.");
    }

    HistoriaDeUsuario historia = repository->findById(historiaId);
    historia.setPessoa(pessoa);

    if (!repository->update(historia))
        throw std::runtime_error("Erro ao vincular pessoa.");
}

void HistoriaUsuarioService::desvincularPessoa(int historiaId)
{
    if (!autenticarPapel(S18_REMOVER_ASSOCIACAO_ENTRE_HU_E_PESSOA))
        throw std::invalid_argument("Acesso negado.");

    HistoriaDeUsuario historia = repository->findById(historiaId);
    Pessoa emptyPessoa(0);
    historia.setPessoa(emptyPessoa);

    if (!repository->update(historia))
        throw std::runtime_error("Erro ao desvincular pessoa.");
}

std::list<HistoriaDeUsuario> HistoriaUsuarioService::listarPorProjeto(Projeto &projeto)
{
    if (!autenticarPapel(S20_LISTAR_HU_ASSOCIADAS_A_PROJETO))
        throw std::invalid_argument("Acesso negado.");

    auto vec = repository->findByProjetoId(projeto.getId());
    return std::list<HistoriaDeUsuario>(vec.begin(), vec.end());
}

std::list<HistoriaDeUsuario> HistoriaUsuarioService::listarPorPlanoSprint(PlanoSprint &planoSprint)
{
    if (!autenticarPapel(S22_LISTAR_HU_ASSOCIADAS_A_PLANO_SPRINT))
        throw std::invalid_argument("Acesso negado.");

    auto vec = repository->findByPlanoSprintId(planoSprint.getId());
    return std::list<HistoriaDeUsuario>(vec.begin(), vec.end());
}

std::list<HistoriaDeUsuario> HistoriaUsuarioService::listarPorPessoa(Pessoa &pessoa)
{
    if (!autenticarPapel(S23_LISTAR_HU_ASSOCIADAS_A_PESSOA))
        throw std::invalid_argument("Acesso negado.");

    auto vec = repository->findByPessoaId(pessoa.getId());
    return std::list<HistoriaDeUsuario>(vec.begin(), vec.end());
}

void HistoriaUsuarioService::moverParaSprint(int historiaId, PlanoSprint &planoSprint)
{
    if (!autenticarPapel(S24_MOVER_HU_DE_PROJETO_PARA_PLANO_SPRINT))
        throw std::invalid_argument("Acesso negado: Somente Mestre Scrum pode mover para sprint.");

    HistoriaDeUsuario historia = repository->findById(historiaId);
    PlanoSprint psDetails = planoSprintRepository->findById(planoSprint.getId());

    auto historiasNoSprint = repository->findByPlanoSprintId(planoSprint.getId());
    int somaEstimativas = historia.getEstimativa().getValor();

    for (const auto &h : historiasNoSprint)
    {
        somaEstimativas += h.getEstimativa().getValor();
    }

    int capacidade = diffDias(psDetails.getDataInicio().getValor(), psDetails.getDataFim().getValor());

    if (somaEstimativas > capacidade)
    {
        throw std::invalid_argument("A soma das estimativas excede a capacidade do Plano de Sprint (" + std::to_string(capacidade) + " dias).");
    }

    historia.setPlanoSprint(psDetails);

    Projeto pZero;
    historia.setProjeto(pZero);

    if (!repository->update(historia))
        throw std::runtime_error("Erro ao mover a historia de usuario.");
}
