#ifndef PROJETO_REPOSITORY_HPP
#define PROJETO_REPOSITORY_HPP

#include <modulos/projeto/Projeto.hpp>
#include <core/RepositoryBase.hpp>

class ProjetoRepository : public RepositoryBase<Projeto>
{
public:
    ProjetoRepository() : RepositoryBase<Projeto>("projeto", {{"id", "INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL"},
                                                              {"codigo", "TEXT NOT NULL"},
                                                              {"nome", "TEXT NOT NULL"},
                                                              {"dataInicio", "TEXT NOT NULL"},
                                                              {"dataFim", "TEXT NOT NULL"}})
    {
    }

    bool save(Projeto &projeto) override;

protected:
    Projeto mapToEntity(SQLite::Statement &query) override;
};

#endif // PROJETO_REPOSITORY_HPP