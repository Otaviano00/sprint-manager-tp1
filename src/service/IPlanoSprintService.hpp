#ifndef IPLANOSPRINTSERVICE_HPP
#define IPLANOSPRINTSERVICE_HPP

#include <list>
#include <stdexcept>
#include <util/ServicoEnum.hpp>
#include <entidades/PlanoSprint.hpp>
#include <entidades/Projeto.hpp>
#include <dominios/Papel.hpp>

/**
 * @brief Contrato de serviços de negócio para a entidade PlanoSprint.
 */
class IPlanoSprintService
{
public:
    /**
     * @brief Verifica autorização do papel logado para um serviço de plano.
     * @param servico Identificador do serviço requisitado.
     * @return true quando o papel atual possui acesso.
     */
    virtual bool autenticarPapel(ServicoEnum servico) = 0;

    /**
     * @brief Cria um novo plano de sprint.
     * @param planoSprint Entidade a ser persistida.
     */
    virtual void criar(PlanoSprint &planoSprint) = 0;

    /**
     * @brief Recupera um plano de sprint pelo identificador.
     * @param id Chave primária do plano.
     * @return PlanoSprint encontrado.
     */
    virtual PlanoSprint listarPorId(int id) = 0;

    /**
     * @brief Lista planos de sprint cadastrados.
     * @return Coleção de planos de sprint.
     */
    virtual std::list<PlanoSprint> listar() = 0;

    /**
     * @brief Atualiza os dados de um plano de sprint.
     * @param planoSprint Entidade com dados atualizados.
     */
    virtual void atualizar(PlanoSprint &planoSprint) = 0;

    /**
     * @brief Exclui um plano de sprint pelo identificador.
     * @param id Chave primária do plano.
     */
    virtual void excluir(int id) = 0;

    /**
     * @brief Lista planos de sprint vinculados a um projeto.
     * @param projeto Projeto pai usado como filtro.
     * @return Coleção de planos associados ao projeto.
     */
    virtual std::list<PlanoSprint> listarPorProjeto(Projeto &projeto) = 0;

    /**
     * @brief Destrutor virtual da interface de plano de sprint.
     */
    virtual ~IPlanoSprintService() = default;
};

#endif // IPLANOSPRINTSERVICE_HPP
