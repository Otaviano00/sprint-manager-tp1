#ifndef PESSOA_REPOSITORY_HPP
#define PESSOA_REPOSITORY_HPP

#include <string>
#include <list>
#include <vector>
#include <map>
#include <cstdarg>
#include <modulos/pessoa/Pessoa.hpp>
#include <core/RepositoryBase.hpp>

#define TABLE_NAME "pessoa"

class PessoaRepository : public RepositoryBase<Pessoa>
{
public:
    PessoaRepository() : RepositoryBase<Pessoa>(TABLE_NAME, {{"id", "INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL"},
                                                             {"email", "TEXT NOT NULL"},
                                                             {"nome", "TEXT NOT NULL"},
                                                             {"senha", "TEXT NOT NULL"}})
    {
    }

    bool save(Pessoa &pessoa) override;

protected:
    Pessoa mapToEntity(SQLite::Statement &query) override;
};

#endif // PESSOA_REPOSITORY_HPP