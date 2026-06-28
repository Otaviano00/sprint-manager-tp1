#include <modulos/projeto/ProjetoRepository.hpp>
#include <modulos/pessoa/PessoaRepository.hpp>

Projeto ProjetoRepository::mapToEntity(SQLite::Statement &query)
{
    long id = query.getColumn("id").getInt();
    Projeto projeto(id);

    Codigo codigo;
    codigo.setValor(query.getColumn("codigo").getString());
    projeto.setCodigo(codigo);

    Nome nome;
    nome.setValor(query.getColumn("nome").getString());
    projeto.setNome(nome);

    Data dataInicio;
    dataInicio.setValor(query.getColumn("dataInicio").getString());
    projeto.setDataInicio(dataInicio);

    Data dataFim;
    dataFim.setValor(query.getColumn("dataFim").getString());
    projeto.setDataFim(dataFim);

    Pessoa pessoa(query.getColumn("pessoaId").getInt());

    PessoaRepository pessoaRepo;
    try
    {
        pessoa = pessoaRepo.findById(pessoa.getId());
    }
    catch (...)
    {
        throw std::invalid_argument("Pessoa associada ao projeto não encontrada.");
    }

    projeto.setPessoa(pessoa);

    return projeto;
}

bool ProjetoRepository::save(Projeto &projeto)
{
    SQLite::Statement query(db, "INSERT INTO " + tableName + " (codigo, nome, dataInicio, dataFim, pessoaId) VALUES (?, ?, ?, ?, ?)");
    query.bind(1, projeto.getCodigo().getValor());
    query.bind(2, projeto.getNome().getValor());
    query.bind(3, projeto.getDataInicio().getValor());
    query.bind(4, projeto.getDataFim().getValor());
    query.bind(5, static_cast<int>(projeto.getPessoa().getId()));

    int rows = query.exec();

    if (rows > 0)
    {
        setEntityId(projeto, db.getLastInsertRowid());
    }

    return rows > 0;
}

bool ProjetoRepository::update(Projeto &projeto)
{
    SQLite::Statement query(db, "UPDATE " + tableName + " SET codigo = ?, nome = ?, dataInicio = ?, dataFim = ?, pessoaId = ? WHERE id = ?");
    query.bind(1, projeto.getCodigo().getValor());
    query.bind(2, projeto.getNome().getValor());
    query.bind(3, projeto.getDataInicio().getValor());
    query.bind(4, projeto.getDataFim().getValor());
    query.bind(5, static_cast<int>(projeto.getPessoa().getId()));
    query.bind(6, static_cast<int>(projeto.getId()));

    int rows = query.exec();
    return rows > 0;
}

std::vector<Projeto> ProjetoRepository::findByPessoaId(int pessoaId)
{
    std::vector<Projeto> projetos;
    SQLite::Statement query(db, "SELECT * FROM " + tableName + " WHERE pessoaId = ?");
    query.bind(1, pessoaId);

    while (query.executeStep())
    {
        projetos.push_back(mapToEntity(query));
    }

    return projetos;
}