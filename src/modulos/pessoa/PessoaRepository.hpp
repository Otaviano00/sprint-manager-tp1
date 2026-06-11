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
    PessoaRepository();

    bool save(Pessoa &pessoa) override;
    bool update(Pessoa &pessoa);
    Pessoa *findByEmail(Email email);
    Pessoa *findByEmailAndSenha(Email email, Senha senha);

protected:
    Pessoa mapToEntity(SQLite::Statement &query) override;
};

#endif // PESSOA_REPOSITORY_HPP