#ifndef IPESSOASERVICE_HPP
#define IPESSOASERVICE_HPP

#include <list>
#include <stdexcept>
#include <util/ServicoEnum.hpp>
#include <modulos/pessoa/Pessoa.hpp>

/**
 * @brief Contrato de serviços de negócio para a entidade Pessoa.
 */
class IPessoaService
{
public:
    /**
     * @brief Verifica se o usuário logado pode executar o serviço informado.
     * @param servico Identificador do serviço solicitado.
     * @return true quando o papel atual possui autorização.
     *
     * @see ServicoEnum Enumeração de serviços do sistema.
     */
    virtual bool autenticarPapel(ServicoEnum servico) = 0;

    /**
     * @brief Cria um novo registro de Pessoa.
     * @param pessoa Entidade a ser persistida.
     */
    virtual void criar(Pessoa &pessoa) = 0;

    /**
     * @brief Recupera uma Pessoa pelo identificador.
     * @param id Chave primária da pessoa.
     * @return Pessoa encontrada.
     */
    virtual Pessoa listarPorId(int id) = 0;

    /**
     * @brief Lista pessoas cadastradas no sistema.
     * @return Coleção de pessoas persistidas.
     */
    virtual std::list<Pessoa> listar() = 0;

    /**
     * @brief Atualiza dados não identificadores de uma Pessoa.
     * @param pessoa Entidade com dados atualizados.
     */
    virtual void atualizar(Pessoa &pessoa) = 0;

    /**
     * @brief Exclui uma Pessoa pelo identificador.
     * @param id Chave primária da pessoa.
     */
    virtual void excluir(int id) = 0;

    /**
     * @brief Destrutor virtual da interface de pessoa.
     */
    virtual ~IPessoaService() = default;
};

#endif // IPESSOASERVICE_HPP