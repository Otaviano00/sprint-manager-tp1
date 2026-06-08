#ifndef PLANOSPRINTSERVICE_HPP
#define PLANOSPRINTSERVICE_HPP

#include <modulos/plano_sprint/IPlanoSprintService.hpp>
#include <modulos/autenticacao/IAutenticacaoService.hpp>
#include <modulos/plano_sprint/PlanoSprintRepository.hpp>

/**
 * @brief Implementa regras de negócio e operações de persistência de PlanoSprint.
 */
class PlanoSprintService : public IPlanoSprintService
{
private:
    IAutenticacaoService *autenticacao;
    PlanoSprintRepository *repository;

public:
    /**
     * @brief Constrói o serviço e inicializa autenticação e repositório.
     */
    PlanoSprintService();

    /**
     * @brief Verifica autorização do papel logado para serviço de plano de sprint.
     * @param servico Identificador do serviço solicitado.
     * @return true quando a operação for permitida.
     */
    bool autenticarPapel(ServicoEnum servico) override;

    /**
     * @brief Cria um novo plano de sprint.
     * @param planoSprint Entidade a ser persistida.
     */
    void criar(PlanoSprint &planoSprint) override;

    /**
     * @brief Busca um plano de sprint pelo identificador.
     * @param id Chave primária do plano.
     * @return PlanoSprint encontrado.
     */
    PlanoSprint listarPorId(int id) override;

    /**
     * @brief Lista planos de sprint cadastrados.
     * @return Coleção de planos.
     */
    std::list<PlanoSprint> listar() override;

    /**
     * @brief Atualiza dados de um plano de sprint.
     * @param planoSprint Entidade com dados atualizados.
     */
    void atualizar(PlanoSprint &planoSprint) override;

    /**
     * @brief Exclui um plano de sprint pelo identificador.
     * @param id Chave primária do plano.
     */
    void excluir(int id) override;

    /**
     * @brief Lista planos de sprint associados a um projeto.
     * @param projeto Projeto usado como filtro.
     * @return Coleção de planos associados.
     */
    std::list<PlanoSprint> listarPorProjeto(Projeto &projeto) override;
};

#endif // PLANOSPRINTSERVICE_HPP
