#include <modulos/historia_usuario/HistoriaDeUsuarioRepository.hpp>
#include <modulos/pessoa/PessoaRepository.hpp>
#include <modulos/projeto/ProjetoRepository.hpp>
#include <modulos/plano_sprint/PlanoSprintRepository.hpp>

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

    Pessoa pessoa(query.getColumn("pessoaId").getInt());
    historia.setPessoa(pessoa);

    Projeto projeto(query.getColumn("projetoId").getInt());
    historia.setProjeto(projeto);

    PlanoSprint sprint(query.getColumn("planoSprintId").getInt());
    historia.setPlanoSprint(sprint);

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
    query.bind(9, static_cast<int>(historia.getPessoa().getId()));
    query.bind(10, static_cast<int>(historia.getProjeto().getId()));
    query.bind(11, static_cast<int>(historia.getPlanoSprint().getId()));

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
    query.bind(9, static_cast<int>(historia.getPessoa().getId()));
    query.bind(10, static_cast<int>(historia.getProjeto().getId()));
    query.bind(11, static_cast<int>(historia.getPlanoSprint().getId()));
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