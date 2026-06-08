#include <modulos/plano_sprint/PlanoSprintRepository.hpp>

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

    return plano;
}

bool PlanoSprintRepository::save(PlanoSprint &plano)
{
    SQLite::Statement query(db, "INSERT INTO " + tableName + " (codigo, nome, dataInicio, dataFim) VALUES (?, ?, ?, ?)");
    query.bind(1, plano.getCodigo().getValor());
    query.bind(2, plano.getNome().getValor());
    query.bind(3, plano.getDataInicio().getValor());
    query.bind(4, plano.getDataFim().getValor());

    int rows = query.exec();

    if (rows > 0)
    {
        setEntityId(plano, db.getLastInsertRowid());
    }

    return rows > 0;
}