#include <repository/HistoriaDeUsuarioRepository.hpp>

HistoriaDeUsuario HistoriaDeUsuarioRepository::mapToEntity(SQLite::Statement &query)
{
    long id = query.getColumn("id").getInt();
    HistoriaDeUsuario historia(id);

    Codigo codigo;
    codigo.setValor(query.getColumn("codigo").getString());
    historia.setCodigo(codigo);

    Texto titulo;
    titulo.setValor(query.getColumn("titulo").getString());
    historia.setTitulo(titulo);

    Texto papel;
    papel.setValor(query.getColumn("papel").getString());
    historia.setPapel(papel);

    Texto acao;
    acao.setValor(query.getColumn("acao").getString());
    historia.setAcao(acao);

    Texto valor;
    valor.setValor(query.getColumn("valor").getString());
    historia.setValor(valor);

    Tempo estimativa;
    estimativa.setValor(query.getColumn("estimativa").getInt());
    historia.setEstimativa(estimativa);

    Prioridade prioridade;
    prioridade.setValor(query.getColumn("prioridade").getString());
    historia.setPrioridade(prioridade);

    Estado estado;
    estado.setValor(query.getColumn("estado").getString());
    historia.setEstado(estado);

    return historia;
}

bool HistoriaDeUsuarioRepository::save(HistoriaDeUsuario &historia)
{
    SQLite::Statement query(db, "INSERT INTO " + tableName + " (codigo, titulo, papel, acao, valor, estimativa, prioridade, estado) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
    query.bind(1, historia.getCodigo().getValor());
    query.bind(2, historia.getTitulo().getValor());
    query.bind(3, historia.getPapel().getValor());
    query.bind(4, historia.getAcao().getValor());
    query.bind(5, historia.getValor().getValor());
    query.bind(6, historia.getEstimativa().getValor());
    query.bind(7, historia.getPrioridade().getValor());
    query.bind(8, historia.getEstado().getValor());

    int rows = query.exec();

    if (rows > 0)
    {
        setEntityId(historia, db.getLastInsertRowid());
    }

    return rows > 0;
}