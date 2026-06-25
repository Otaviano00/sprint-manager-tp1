#include <modulos/pessoa/PessoaService.hpp>
#include <modulos/autenticacao/AutenticacaoService.hpp>

PessoaService::PessoaService()
{
    autenticacao = AutenticacaoService::getInstance();
    repository = new PessoaRepository();
}

PessoaService::~PessoaService()
{
    delete repository;
}

bool PessoaService::autenticarPapel(ServicoEnum servico)
{
    if (!autenticacao->isLoggedIn())
    {
        throw std::invalid_argument("Usuário não autenticado");
    }

    switch (servico)
    {
    case S1_CRIAR_PESSOA:
    case S2_LER_PESSOA:
    case S2_LISTAR_PESSOA:
    case S3_ATUALIZAR_PESSOA:
    case S4_EXCLUIR_PESSOA:
        return true;
    default:
        throw std::invalid_argument("Serviço desconhecido ou não pertence a Pessoa");
    }
}

void PessoaService::criar(Pessoa &pessoa)
{
    if (!repository->save(pessoa))
    {
        throw std::runtime_error("Falha ao cadastrar pessoa");
    }
}

Pessoa PessoaService::listarPorId(int id)
{
    return repository->findById(id);
}

std::list<Pessoa> PessoaService::listar()
{
    std::list<Pessoa> pessoas;
    std::vector<Pessoa> resultado = repository->findAll();

    for (const auto &pessoa : resultado)
    {
        pessoas.push_back(pessoa);
    }

    return pessoas;
}

void PessoaService::atualizar(Pessoa &pessoa)
{
    if (!repository->update(pessoa))
    {
        throw std::runtime_error("Falha ao atualizar pessoa");
    }
}

void PessoaService::excluir(int id)
{
    if (!repository->deleteById(id))
    {
        throw std::runtime_error("Falha ao excluir pessoa");
    }
}
