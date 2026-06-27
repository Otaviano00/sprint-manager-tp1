#include <modulos/projeto/ProjetoRepository.hpp>

void ProjetoRepository::ensureSchema()
{
    SQLite::Statement pragma(db, "PRAGMA table_info(projeto)");
    bool hasPessoaId = false;

    while (pragma.executeStep())
    {
        if (pragma.getColumn("name").getString() == "pessoaId")
        {
            hasPessoaId = true;
            break;
        }
    }

    if (!hasPessoaId)
    {
        db.exec("ALTER TABLE projeto ADD COLUMN pessoaId INTEGER NOT NULL DEFAULT 0");
    }
}

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