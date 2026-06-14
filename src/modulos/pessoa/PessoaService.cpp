#include <modulos/pessoa/PessoaService.hpp>
#include <modulos/autenticacao/AutenticacaoService.hpp>

PessoaService::PessoaService()
{
    autenticacao = AutenticacaoService::getInstance();
    repository = new PessoaRepository();
}

bool PessoaService::autenticarPapel(ServicoEnum servico)
{
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
    if (!autenticarPapel(S1_CRIAR_PESSOA))
    {
        throw std::invalid_argument("Sem permissao para criar pessoa");
    }

    if (repository->findByEmail(pessoa.getEmail()) != nullptr)
    {
        throw std::invalid_argument("Ja existe uma pessoa com esse email");
    }

    if (!repository->save(pessoa))
    {
        throw std::runtime_error("Erro ao salvar pessoa");
    }
}

Pessoa PessoaService::listarPorId(int id)
{
    if (!autenticarPapel(S2_LER_PESSOA))
    {
        throw std::invalid_argument("Sem permissao para listar pessoa");
    }

    return repository->findById(id);
}

std::list<Pessoa> PessoaService::listar()
{
    if (!autenticarPapel(S2_LISTAR_PESSOA))
    {
        throw std::invalid_argument("Sem permissao para listar pessoas");
    }

    auto pessoas = repository->findAll();

    return std::list<Pessoa>(
        pessoas.begin(),
        pessoas.end());
}

void PessoaService::atualizar(Pessoa &pessoa)
{
    if (!autenticarPapel(S3_ATUALIZAR_PESSOA))
    {
        throw std::invalid_argument("Sem permissao para atualizar pessoa");
    }

    if (!repository->update(pessoa))
    {
        throw std::runtime_error("Pessoa nao encontrada");
    }
}

void PessoaService::excluir(int id)
{
    if (!autenticarPapel(S4_EXCLUIR_PESSOA))
    {
        throw std::invalid_argument("Sem permissao para excluir pessoa");
    }

    if (!repository->deleteById(id))
    {
        throw std::runtime_error("Pessoa nao encontrada");
    }
}