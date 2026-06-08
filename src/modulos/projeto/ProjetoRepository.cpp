#include <modulos/projeto/ProjetoRepository.hpp>

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

    return projeto;
}

bool ProjetoRepository::save(Projeto &projeto)
{
    SQLite::Statement query(db, "INSERT INTO " + tableName + " (codigo, nome, dataInicio, dataFim) VALUES (?, ?, ?, ?)");
    query.bind(1, projeto.getCodigo().getValor());
    query.bind(2, projeto.getNome().getValor());
    query.bind(3, projeto.getDataInicio().getValor());
    query.bind(4, projeto.getDataFim().getValor());

    int rows = query.exec();

    if (rows > 0)
    {
        setEntityId(projeto, db.getLastInsertRowid());
    }

    return rows > 0;
}