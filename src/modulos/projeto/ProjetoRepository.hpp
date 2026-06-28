#ifndef PROJETO_REPOSITORY_HPP
#define PROJETO_REPOSITORY_HPP

#include <modulos/projeto/Projeto.hpp>
#include <core/RepositoryBase.hpp>

class ProjetoRepository : public RepositoryBase<Projeto>
{
public:
    ProjetoRepository();

    bool save(Projeto &projeto) override;
    bool update(Projeto &projeto);
    std::vector<Projeto> findByPessoaId(int pessoaId);

protected:
    Projeto mapToEntity(SQLite::Statement &query) override;
};

#endif // PROJETO_REPOSITORY_HPP