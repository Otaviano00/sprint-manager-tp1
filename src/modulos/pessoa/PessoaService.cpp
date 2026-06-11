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

void PessoaService::criar(Pessoa &pessoa) {}
Pessoa PessoaService::listarPorId(int id) { return Pessoa(); }
std::list<Pessoa> PessoaService::listar() { return std::list<Pessoa>(); }
void PessoaService::atualizar(Pessoa &pessoa) {}
void PessoaService::excluir(int id) {}
