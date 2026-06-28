#ifndef PLANOSPRINT_REPOSITORY_HPP
#define PLANOSPRINT_REPOSITORY_HPP

#include <modulos/plano_sprint/PlanoSprint.hpp>
#include <core/RepositoryBase.hpp>

class PlanoSprintRepository : public RepositoryBase<PlanoSprint>
{
public:
    PlanoSprintRepository();

    bool save(PlanoSprint &plano) override;

protected:
    PlanoSprint mapToEntity(SQLite::Statement &query) override;
};

#endif // PLANOSPRINT_REPOSITORY_HPP