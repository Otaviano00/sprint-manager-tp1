#include <modulos/historia_usuario/HistoriaDeUsuarioRepository.hpp>
#include <modulos/historia_usuario/HistoriaDeUsuario.hpp>
#include <core/RepositoryBase.hpp>
#include <modulos/pessoa/PessoaRepository.hpp>
#include <modulos/projeto/ProjetoRepository.hpp>
#include <modulos/plano_sprint/PlanoSprintRepository.hpp>

HistoriaDeUsuarioRepository::HistoriaDeUsuarioRepository()
    : RepositoryBase<HistoriaDeUsuario>("historiadeusuario", {{"id", "INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL"},
                                                              {"codigo", "TEXT NOT NULL UNIQUE"},
                                                              {"titulo", "TEXT NOT NULL"},
                                                              {"papel", "TEXT NOT NULL"},
                                                              {"acao", "TEXT NOT NULL"},
                                                              {"valor", "TEXT NOT NULL"},
                                                              {"estimativa", "INTEGER NOT NULL"},
                                                              {"prioridade", "TEXT NOT NULL"},
                                                              {"estado", "TEXT NOT NULL"},
                                                              {"pessoaId", "INTEGER DEFAULT NULL REFERENCES pessoa(id) ON DELETE SET NULL ON UPDATE CASCADE"},
                                                              {"projetoId", "INTEGER DEFAULT NULL REFERENCES projeto(id) ON DELETE CASCADE ON UPDATE CASCADE"},
                                                              {"planoSprintId", "INTEGER DEFAULT NULL REFERENCES planosprint(id) ON DELETE CASCADE ON UPDATE CASCADE"}})
{
}

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

    if (!query.getColumn("pessoaId").isNull())
        historia.setPessoa(Pessoa(query.getColumn("pessoaId").getInt()));

    if (!query.getColumn("projetoId").isNull())
        historia.setProjeto(Projeto(query.getColumn("projetoId").getInt()));

    if (!query.getColumn("planoSprintId").isNull())
        historia.setPlanoSprint(PlanoSprint(query.getColumn("planoSprintId").getInt()));

    return historia;
}

bool HistoriaDeUsuarioRepository::save(HistoriaDeUsuario &historia)
{
    SQLite::Statement query(db, "INSERT INTO " + tableName + " (codigo, titulo, papel, acao, valor, estimativa, prioridade, estado, pessoaId, projetoId, planoSprintId) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.bind(1, historia.getCodigo().getValor());
    query.bind(2, historia.getTitulo().getValor());
    query.bind(3, historia.getPapel().getValor());
    query.bind(4, historia.getAcao().getValor());
    query.bind(5, historia.getValor().getValor());
    query.bind(6, historia.getEstimativa().getValor());
    query.bind(7, historia.getPrioridade().getValor());
    query.bind(8, historia.getEstado().getValor());
    if (historia.getPessoa().getId() != 0)
        query.bind(9, static_cast<int>(historia.getPessoa().getId()));
    else
        query.bind(9); // NULL

    if (historia.getProjeto().getId() != 0)
        query.bind(10, static_cast<int>(historia.getProjeto().getId()));
    else
        query.bind(10); // NULL

    if (historia.getPlanoSprint().getId() != 0)
        query.bind(11, static_cast<int>(historia.getPlanoSprint().getId()));
    else
        query.bind(11); // NULL

    int rows = query.exec();

    if (rows > 0)
    {
        setEntityId(historia, db.getLastInsertRowid());
    }

    return rows > 0;
}

bool HistoriaDeUsuarioRepository::update(HistoriaDeUsuario &historia)
{
    SQLite::Statement query(db, "UPDATE " + tableName + " SET codigo = ?, titulo = ?, papel = ?, acao = ?, valor = ?, estimativa = ?, prioridade = ?, estado = ?, pessoaId = ?, projetoId = ?, planoSprintId = ? WHERE id = ?");
    query.bind(1, historia.getCodigo().getValor());
    query.bind(2, historia.getTitulo().getValor());
    query.bind(3, historia.getPapel().getValor());
    query.bind(4, historia.getAcao().getValor());
    query.bind(5, historia.getValor().getValor());
    query.bind(6, historia.getEstimativa().getValor());
    query.bind(7, historia.getPrioridade().getValor());
    query.bind(8, historia.getEstado().getValor());
    if (historia.getPessoa().getId() != 0)
        query.bind(9, static_cast<int>(historia.getPessoa().getId()));
    else
        query.bind(9); // NULL

    if (historia.getProjeto().getId() != 0)
        query.bind(10, static_cast<int>(historia.getProjeto().getId()));
    else
        query.bind(10); // NULL

    if (historia.getPlanoSprint().getId() != 0)
        query.bind(11, static_cast<int>(historia.getPlanoSprint().getId()));
    else
        query.bind(11); // NULL

    query.bind(12, static_cast<int>(historia.getId()));

    int rows = query.exec();
    return rows > 0;
}

std::vector<HistoriaDeUsuario> HistoriaDeUsuarioRepository::findByPessoaId(int pessoaId)
{
    std::vector<HistoriaDeUsuario> historias;
    SQLite::Statement query(db, "SELECT * FROM " + tableName + " WHERE pessoaId = ?");
    query.bind(1, pessoaId);

    while (query.executeStep())
    {
        historias.push_back(mapToEntity(query));
    }

    return historias;
}

std::vector<HistoriaDeUsuario> HistoriaDeUsuarioRepository::findByProjetoId(int projetoId)
{
    std::vector<HistoriaDeUsuario> historias;
    SQLite::Statement query(db, "SELECT * FROM " + tableName + " WHERE projetoId = ?");
    query.bind(1, projetoId);

    while (query.executeStep())
    {
        historias.push_back(mapToEntity(query));
    }

    return historias;
}

std::vector<HistoriaDeUsuario> HistoriaDeUsuarioRepository::findByPlanoSprintId(int planoSprintId)
{
    std::vector<HistoriaDeUsuario> historias;
    SQLite::Statement query(db, "SELECT * FROM " + tableName + " WHERE planoSprintId = ?");
    query.bind(1, planoSprintId);

    while (query.executeStep())
    {
        historias.push_back(mapToEntity(query));
    }

    return historias;
}