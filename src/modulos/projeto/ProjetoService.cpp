#include <modulos/projeto/ProjetoService.hpp>
#include <modulos/autenticacao/AutenticacaoService.hpp>

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

void ProjetoService::criar(Projeto &projeto)
{
    if (!repository->save(projeto))
    {
        throw std::runtime_error("Erro ao persistir projeto no banco de dados.");
    }
}

Projeto ProjetoService::listarPorId(int id)
{
    try
    {
        return repository->findById(id);
    }
    catch (const std::runtime_error &e)
    {
        throw std::invalid_argument("Projeto com o ID fornecido não encontrado.");
    }
}

std::list<Projeto> ProjetoService::listar()
{
    std::vector<Projeto> projetos = repository->findAll();
    return std::list<Projeto>(projetos.begin(), projetos.end());
}

void ProjetoService::atualizar(Projeto &projeto)
{
    // Atualiza nome e datas
    SQLite::Database db(DATABASE_NAME, SQLite::OPEN_READWRITE);
    SQLite::Statement query(db, "UPDATE projeto SET nome = ?, dataInicio = ?, dataFim = ? WHERE id = ?");
    
    query.bind(1, projeto.getNome().getValor());
    query.bind(2, projeto.getDataInicio().getValor());
    query.bind(3, projeto.getDataFim().getValor());
    query.bind(4, static_cast<int>(projeto.getId()));

    int rows = query.exec();
    if (rows == 0)
    {
        throw std::runtime_error("Projeto não encontrado ou erro ao atualizar.");
    }
}

void ProjetoService::excluir(int id)
{
    if (!repository->deleteById(id))
    {
        throw std::runtime_error("Projeto não encontrado ou erro ao excluir.");
    }
}

std::list<Projeto> ProjetoService::listarPorPessoa(Pessoa &pessoa)
{
    // Implementação futura: listar projetos associados a uma pessoa
    return std::list<Projeto>();
}
