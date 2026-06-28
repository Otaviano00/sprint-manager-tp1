#ifndef HISTORIADEUSUARIO_REPOSITORY_HPP
#define HISTORIADEUSUARIO_REPOSITORY_HPP

#include <modulos/historia_usuario/HistoriaDeUsuario.hpp>
#include <core/RepositoryBase.hpp>

class HistoriaDeUsuarioRepository : public RepositoryBase<HistoriaDeUsuario>
{
public:
    HistoriaDeUsuarioRepository();

    bool save(HistoriaDeUsuario &historia) override;
    bool update(HistoriaDeUsuario &historia);
    std::vector<HistoriaDeUsuario> findByPessoaId(int pessoaId);
    std::vector<HistoriaDeUsuario> findByProjetoId(int projetoId);
    std::vector<HistoriaDeUsuario> findByPlanoSprintId(int planoSprintId);

protected:
    HistoriaDeUsuario mapToEntity(SQLite::Statement &query) override;
};

#endif // HISTORIADEUSUARIO_REPOSITORY_HPP