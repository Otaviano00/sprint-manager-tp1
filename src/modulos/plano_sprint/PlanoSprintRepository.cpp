#include <modulos/plano_sprint/PlanoSprintRepository.hpp>

PlanoSprintRepository::PlanoSprintRepository()
    : RepositoryBase<PlanoSprint>("planosprint", {{"id", "INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL"},
                                                  {"codigo", "TEXT NOT NULL UNIQUE"},
                                                  {"nome", "TEXT NOT NULL"},
                                                  {"dataInicio", "TEXT NOT NULL"},
                                                  {"dataFim", "TEXT NOT NULL"},
                                                  {"projetoId", "INTEGER DEFAULT NULL REFERENCES projeto(id) ON DELETE CASCADE ON UPDATE CASCADE"}})
{
}

PlanoSprint PlanoSprintRepository::mapToEntity(SQLite::Statement &query)
{
    long id = query.getColumn("id").getInt();
    PlanoSprint plano(id);

    Codigo codigo;
    codigo.setValor(query.getColumn("codigo").getString());
    plano.setCodigo(codigo);

    Nome nome;
    nome.setValor(query.getColumn("nome").getString());
    plano.setNome(nome);

    Data dataInicio;
    dataInicio.setValor(query.getColumn("dataInicio").getString());
    plano.setDataInicio(dataInicio);

    Data dataFim;
    dataFim.setValor(query.getColumn("dataFim").getString());
    plano.setDataFim(dataFim);

    if (!query.getColumn("projetoId").isNull())
        plano.setProjeto(Projeto(query.getColumn("projetoId").getInt()));

    return plano;
}

bool PlanoSprintRepository::update(PlanoSprint &plano)
{
    SQLite::Statement query(db, "UPDATE " + tableName + " SET codigo = ?, nome = ?, dataInicio = ?, dataFim = ?, projetoId = ? WHERE id = ?");
    query.bind(1, plano.getCodigo().getValor());
    query.bind(2, plano.getNome().getValor());
    query.bind(3, plano.getDataInicio().getValor());
    query.bind(4, plano.getDataFim().getValor());

    if (plano.getProjeto().getId() != 0)
        query.bind(5, static_cast<int>(plano.getProjeto().getId()));
    else
        query.bind(5); // NULL

    query.bind(6, static_cast<int>(plano.getId()));
    return query.exec() > 0;
}

bool PlanoSprintRepository::save(PlanoSprint &plano)
{
    SQLite::Statement query(db, "INSERT INTO " + tableName + " (codigo, nome, dataInicio, dataFim, projetoId) VALUES (?, ?, ?, ?, ?)");
    query.bind(1, plano.getCodigo().getValor());
    query.bind(2, plano.getNome().getValor());
    query.bind(3, plano.getDataInicio().getValor());
    query.bind(4, plano.getDataFim().getValor());

    if (plano.getProjeto().getId() != 0)
        query.bind(5, static_cast<int>(plano.getProjeto().getId()));
    else
        query.bind(5); // NULL

    int rows = query.exec();

    if (rows > 0)
    {
        setEntityId(plano, db.getLastInsertRowid());
    }

    return rows > 0;
}

std::vector<PlanoSprint> PlanoSprintRepository::findByProjetoId(long projetoId)
{
    SQLite::Statement query(db, "SELECT * FROM " + tableName + " WHERE projetoId = ?");
    query.bind(1, static_cast<int>(projetoId));

    std::vector<PlanoSprint> planos;
    while (query.executeStep())
    {
        planos.push_back(mapToEntity(query));
    }

    return planos;
}