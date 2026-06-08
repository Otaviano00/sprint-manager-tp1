#include <service/ProjetoService.hpp>
#include <service/AutenticacaoService.hpp>

ProjetoService::ProjetoService()
{
    autenticacao = AutenticacaoService::getInstance();
    repository = new ProjetoRepository();
}

bool ProjetoService::autenticarPapel(ServicoEnum servico)
{
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

void ProjetoService::criar(Projeto &projeto) {}
Projeto ProjetoService::listarPorId(int id) { return Projeto(); }
std::list<Projeto> ProjetoService::listar() { return std::list<Projeto>(); }
void ProjetoService::atualizar(Projeto &projeto) {}
void ProjetoService::excluir(int id) {}
std::list<Projeto> ProjetoService::listarPorPessoa(Pessoa &pessoa) { return std::list<Projeto>(); }
