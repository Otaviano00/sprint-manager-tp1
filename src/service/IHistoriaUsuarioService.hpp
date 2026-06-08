#ifndef IHISTORIAUSUARIOSERVICE_HPP
#define IHISTORIAUSUARIOSERVICE_HPP

#include <list>
#include <string>
#include <stdexcept>
#include <service/IAutenticacaoService.hpp>
#include <util/ServicoEnum.hpp>
#include <entidades/HistoriaDeUsuario.hpp>
#include <entidades/Pessoa.hpp>
#include <entidades/Projeto.hpp>
#include <entidades/PlanoSprint.hpp>
#include <dominios/Papel.hpp>

/**
 * @brief Contrato de serviços de negócio para a entidade HistoriaDeUsuario.
 */
class IHistoriaUsuarioService
{
protected:
    IAutenticacaoService *autenticacao;

public:
    /**
     * @brief Verifica autorização do papel logado para o serviço solicitado.
     * @param servico Identificador do serviço.
     * @return true quando a execução é permitida.
     */
    virtual bool autenticarPapel(ServicoEnum servico) = 0;

    /**
     * @brief Cria uma nova história de usuário.
     * @param historiaUsuario Entidade a ser persistida.
     */
    virtual void criar(HistoriaDeUsuario &historiaUsuario) = 0;

    /**
     * @brief Recupera uma história de usuário pelo identificador.
     * @param id Chave primária da história.
     * @return História encontrada.
     */
    virtual HistoriaDeUsuario listarPorId(int id) = 0;

    /**
     * @brief Lista histórias de usuário cadastradas.
     * @return Coleção de histórias.
     */
    virtual std::list<HistoriaDeUsuario> listar() = 0;

    /**
     * @brief Atualiza os dados de uma história de usuário.
     * @param historiaUsuario Entidade com alterações aplicadas.
     */
    virtual void atualizar(HistoriaDeUsuario &historiaUsuario) = 0;

    /**
     * @brief Exclui uma história de usuário pelo identificador.
     * @param id Chave primária da história.
     */
    virtual void excluir(int id) = 0;

    /**
     * @brief Altera o estado da história de usuário atual.
     * @param estado Novo estado a ser aplicado.
     */
    virtual void alterarEstado(std::string estado) = 0;

    /**
     * @brief Associa uma pessoa à história de usuário.
     * @param pessoa Pessoa a ser vinculada.
     */
    virtual void vincularPessoa(Pessoa &pessoa) = 0;

    /**
     * @brief Remove a associação de uma pessoa com a história de usuário.
     * @param pessoa Pessoa a ser desvinculada.
     */
    virtual void desvincularPessoa(Pessoa &pessoa) = 0;

    /**
     * @brief Lista histórias associadas a um projeto.
     * @param projeto Projeto usado como filtro.
     * @return Coleção de histórias associadas.
     */
    virtual std::list<HistoriaDeUsuario> listarPorProjeto(Projeto &projeto) = 0;

    /**
     * @brief Lista histórias associadas a um plano de sprint.
     * @param planoSprint Plano usado como filtro.
     * @return Coleção de histórias associadas.
     */
    virtual std::list<HistoriaDeUsuario> listarPorPlanoSprint(PlanoSprint &planoSprint) = 0;

    /**
     * @brief Lista histórias associadas a uma pessoa.
     * @param pessoa Pessoa usada como filtro.
     * @return Coleção de histórias associadas.
     */
    virtual std::list<HistoriaDeUsuario> listarPorPessoa(Pessoa &pessoa) = 0;

    /**
     * @brief Move uma história de usuário para um plano de sprint.
     * @param planoSprint Destino da movimentação.
     */
    virtual void moverParaSprint(PlanoSprint &planoSprint) = 0;

    /**
     * @brief Destrutor virtual da interface de história de usuário.
     */
    virtual ~IHistoriaUsuarioService() = default;
};

#endif // IHISTORIAUSUARIOSERVICE_HPP
