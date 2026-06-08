#ifndef HISTORIAUSUARIOSERVICE_HPP
#define HISTORIAUSUARIOSERVICE_HPP

#include <modulos/historia_usuario/IHistoriaUsuarioService.hpp>
#include <modulos/historia_usuario/HistoriaDeUsuarioRepository.hpp>

/**
 * @brief Implementa regras de negócio e persistência de HistoriaDeUsuario.
 */
class HistoriaUsuarioService : public IHistoriaUsuarioService
{
private:
    IAutenticacaoService *autenticacao;
    HistoriaDeUsuarioRepository *repository;

public:
    /**
     * @brief Constrói o serviço e inicializa autenticação e repositório.
     */
    HistoriaUsuarioService();

    /**
     * @brief Verifica autorização do papel logado para o serviço solicitado.
     * @param servico Identificador do serviço.
     * @return true quando a operação for permitida.
     */
    bool autenticarPapel(ServicoEnum servico) override;

    /**
     * @brief Cria uma nova história de usuário.
     * @param historiaUsuario Entidade a ser persistida.
     */
    void criar(HistoriaDeUsuario &historiaUsuario) override;

    /**
     * @brief Busca uma história de usuário pelo identificador.
     * @param id Chave primária da história.
     * @return História encontrada.
     */
    HistoriaDeUsuario listarPorId(int id) override;

    /**
     * @brief Lista histórias de usuário cadastradas.
     * @return Coleção de histórias.
     */
    std::list<HistoriaDeUsuario> listar() override;

    /**
     * @brief Atualiza dados de uma história de usuário.
     * @param historiaUsuario Entidade com dados atualizados.
     */
    void atualizar(HistoriaDeUsuario &historiaUsuario) override;

    /**
     * @brief Exclui uma história de usuário pelo identificador.
     * @param id Chave primária da história.
     */
    void excluir(int id) override;

    /**
     * @brief Altera o estado de uma história de usuário.
     * @param estado Novo estado da história.
     */
    void alterarEstado(std::string estado) override;

    /**
     * @brief Associa uma pessoa à história de usuário.
     * @param pessoa Pessoa a ser vinculada.
     */
    void vincularPessoa(Pessoa &pessoa) override;

    /**
     * @brief Remove associação de uma pessoa da história de usuário.
     * @param pessoa Pessoa a ser desvinculada.
     */
    void desvincularPessoa(Pessoa &pessoa) override;

    /**
     * @brief Lista histórias associadas a um projeto.
     * @param projeto Projeto usado como filtro.
     * @return Coleção de histórias associadas.
     */
    std::list<HistoriaDeUsuario> listarPorProjeto(Projeto &projeto) override;

    /**
     * @brief Lista histórias associadas a um plano de sprint.
     * @param planoSprint Plano usado como filtro.
     * @return Coleção de histórias associadas.
     */
    std::list<HistoriaDeUsuario> listarPorPlanoSprint(PlanoSprint &planoSprint) override;

    /**
     * @brief Lista histórias associadas a uma pessoa.
     * @param pessoa Pessoa usada como filtro.
     * @return Coleção de histórias associadas.
     */
    std::list<HistoriaDeUsuario> listarPorPessoa(Pessoa &pessoa) override;

    /**
     * @brief Move história de usuário para um plano de sprint.
     * @param planoSprint Destino da movimentação.
     */
    void moverParaSprint(PlanoSprint &planoSprint) override;
};

#endif // HISTORIAUSUARIOSERVICE_HPP
