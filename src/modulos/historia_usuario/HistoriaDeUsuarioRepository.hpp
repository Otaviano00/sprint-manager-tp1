#ifndef HISTORIADEUSUARIO_REPOSITORY_HPP
#define HISTORIADEUSUARIO_REPOSITORY_HPP

#include <modulos/historia_usuario/HistoriaDeUsuario.hpp>
#include <core/RepositoryBase.hpp>

class HistoriaDeUsuarioRepository : public RepositoryBase<HistoriaDeUsuario>
{
public:
    HistoriaDeUsuarioRepository() : RepositoryBase<HistoriaDeUsuario>("historiadeusuario", {{"id", "INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL"},
                                                                                            {"codigo", "TEXT NOT NULL"},
                                                                                            {"titulo", "TEXT NOT NULL"},
                                                                                            {"papel", "TEXT NOT NULL"},
                                                                                            {"acao", "TEXT NOT NULL"},
                                                                                            {"valor", "TEXT NOT NULL"},
                                                                                            {"estimativa", "INTEGER NOT NULL"},
                                                                                            {"prioridade", "INTEGER NOT NULL"},
                                                                                            {"estado", "TEXT NOT NULL"},
                                                                                            {"pessoaId", "INTEGER NOT NULL"},
                                                                                            {"projetoId", "INTEGER NOT NULL"},
                                                                                            {"planoSprintId", "INTEGER NOT NULL"}}) {}

    bool save(HistoriaDeUsuario &historia) override;
    bool update(HistoriaDeUsuario &historia);
    std::vector<HistoriaDeUsuario> findByPessoaId(int pessoaId);
    std::vector<HistoriaDeUsuario> findByProjetoId(int projetoId);
    std::vector<HistoriaDeUsuario> findByPlanoSprintId(int planoSprintId);

protected:
    HistoriaDeUsuario mapToEntity(SQLite::Statement &query) override;
};

#endif // HISTORIADEUSUARIO_REPOSITORY_HPP