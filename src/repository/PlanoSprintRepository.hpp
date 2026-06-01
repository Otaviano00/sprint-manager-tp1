#ifndef PLANOSPRINT_REPOSITORY_HPP
#define PLANOSPRINT_REPOSITORY_HPP

#include <entidades/PlanoSprint.hpp>
#include <repository/RepositoryBase.hpp>

class PlanoSprintRepository : public RepositoryBase<PlanoSprint>
{
public:
    PlanoSprintRepository() : RepositoryBase<PlanoSprint>("planosprint", {{"id", "INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL"},
                                                                          {"codigo", "TEXT NOT NULL"},
                                                                          {"nome", "TEXT NOT NULL"},
                                                                          {"dataInicio", "TEXT NOT NULL"},
                                                                          {"dataFim", "TEXT NOT NULL"}})
    {
    }

    bool save(PlanoSprint &plano) override;

protected:
    PlanoSprint mapToEntity(SQLite::Statement &query) override;
};

#endif // PLANOSPRINT_REPOSITORY_HPP