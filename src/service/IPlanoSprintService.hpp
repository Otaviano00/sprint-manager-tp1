#ifndef IPLANOSPRINTSERVICE_HPP
#define IPLANOSPRINTSERVICE_HPP

#include <list>
#include <stdexcept>
#include <util/ServicoEnum.hpp>
#include <entidades/PlanoSprint.hpp>
#include <entidades/Projeto.hpp>
#include <dominios/Papel.hpp>

class IPlanoSprintService
{
public:
    virtual bool autenticarPapel(ServicoEnum servico) = 0;

    // CRUD
    virtual void criar(PlanoSprint &planoSprint) = 0;
    virtual PlanoSprint listarPorId(int id) = 0;
    virtual std::list<PlanoSprint> listar() = 0;
    virtual void atualizar(PlanoSprint &planoSprint) = 0;
    virtual void excluir(int id) = 0;

    // Relacionamentos
    virtual std::list<PlanoSprint> listarPorProjeto(Projeto &projeto) = 0;

    virtual ~IPlanoSprintService() = default;
};

#endif // IPLANOSPRINTSERVICE_HPP
