#include <modulos/projeto/ProjetoService.hpp>
#include <modulos/autenticacao/AutenticacaoService.hpp>
#include <modulos/pessoa/PessoaRepository.hpp>

ProjetoService::ProjetoService()
{
    autenticacao = AutenticacaoService::getInstance();
    repository = new ProjetoRepository();
}

ProjetoService::~ProjetoService()
{
    delete repository;
}

bool ProjetoService::autenticarPapel(ServicoEnum servico)
{
    if (!autenticacao->isLoggedIn())
    {
        throw std::invalid_argument("Usuário não autenticado");
    }

    PapelEnum papel = autenticacao->getPapel();

    switch (servico)
    {
    case S5_CRIAR_PROJETO:
    case S7_ATUALIZAR_PROJETO:
    case S8_EXCLUIR_PROJETO:
        return papel == PapelEnum::PROPRIETARIO_DE_PRODUTO;

    case S6_LER_PROJETO:
    case S19_LISTAR_PROJETOS_ASSOCIADOS_A_PESSOA:
        return true;

    default:
        throw std::invalid_argument("Serviço desconhecido ou não pertence a Projeto");
    }
}

void ProjetoService::criar(Projeto &projeto)
{
    if (!autenticarPapel(S5_CRIAR_PROJETO))
    {
        throw std::invalid_argument("Você não tem permissão para criar projetos.");
    }

    if (projeto.getPessoa().getId() <= 0)
    {
        throw std::invalid_argument("É necessário informar uma pessoa associada ao projeto.");
    }

    PessoaRepository pessoaRepo;
    Pessoa associada;
    try
    {
        associada = pessoaRepo.findById(projeto.getPessoa().getId());
    }
    catch (...)
    {
        throw std::invalid_argument("A pessoa associada não foi encontrada.");
    }

    if (associada.getPapel().getValor() == "DESENVOLVEDOR")
    {
        throw std::invalid_argument("Um projeto não pode ser associado a um DESENVOLVEDOR.");
    }

    if (!repository->save(projeto))
    {
        throw std::runtime_error("Falha ao cadastrar projeto");
    }
}

Projeto ProjetoService::listarPorId(int id)
{
    if (!autenticarPapel(S6_LER_PROJETO))
    {
        throw std::invalid_argument("Você não tem permissão para consultar projetos.");
    }

    return repository->findById(id);
}

std::list<Projeto> ProjetoService::listar()
{
    if (!autenticarPapel(S6_LER_PROJETO))
    {
        throw std::invalid_argument("Você não tem permissão para listar projetos.");
    }

    std::list<Projeto> projetos;
    std::vector<Projeto> resultado = repository->findAll();

    for (const auto &projeto : resultado)
    {
        projetos.push_back(projeto);
    }

    return projetos;
}

void ProjetoService::atualizar(Projeto &projeto)
{
    if (!autenticarPapel(S7_ATUALIZAR_PROJETO))
    {
        throw std::invalid_argument("Você não tem permissão para atualizar projetos.");
    }

    if (projeto.getPessoa().getId() <= 0)
    {
        throw std::invalid_argument("É necessário informar uma pessoa associada ao projeto.");
    }

    PessoaRepository pessoaRepo;
    Pessoa associada;
    try
    {
        associada = pessoaRepo.findById(projeto.getPessoa().getId());
    }
    catch (...)
    {
        throw std::invalid_argument("A pessoa associada não foi encontrada.");
    }

    if (associada.getPapel().getValor() == "DESENVOLVEDOR")
    {
        throw std::invalid_argument("Um projeto não pode ser associado a um DESENVOLVEDOR.");
    }

    if (!repository->update(projeto))
    {
        throw std::runtime_error("Falha ao atualizar projeto");
    }
}

void ProjetoService::excluir(int id)
{
    if (!autenticarPapel(S8_EXCLUIR_PROJETO))
    {
        throw std::invalid_argument("Você não tem permissão para excluir projetos.");
    }

    if (!repository->deleteById(id))
    {
        throw std::runtime_error("Falha ao excluir projeto");
    }
}

std::list<Projeto> ProjetoService::listarPorPessoa(Pessoa &pessoa)
{
    if (!autenticarPapel(S19_LISTAR_PROJETOS_ASSOCIADOS_A_PESSOA))
    {
        throw std::invalid_argument("Você não tem permissão para listar projetos associados à pessoa.");
    }

    std::list<Projeto> projetos;
    std::vector<Projeto> resultado = repository->findByPessoaId(pessoa.getId());

    for (const auto &projeto : resultado)
    {
        projetos.push_back(projeto);
    }

    return projetos;
}
