#ifndef HISTORIADEUSUARIO_REPOSITORY_HPP
#define HISTORIADEUSUARIO_REPOSITORY_HPP

#include <entidades/HistoriaDeUsuario.hpp>
#include <repository/RepositoryBase.hpp>

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
                                                                                            {"estado", "TEXT NOT NULL"}})
    {
    }

    bool save(HistoriaDeUsuario &historia) override;

protected:
    HistoriaDeUsuario mapToEntity(SQLite::Statement &query) override;
};

#endif // HISTORIADEUSUARIO_REPOSITORY_HPP