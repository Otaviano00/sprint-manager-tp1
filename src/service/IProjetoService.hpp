#ifndef IPROJETOSERVICE_HPP
#define IPROJETOSERVICE_HPP

#include <list>
#include <stdexcept>
#include <util/ServicoEnum.hpp>
#include <entidades/Projeto.hpp>
#include <entidades/Pessoa.hpp>
#include <dominios/Papel.hpp>

/**
 * @brief Contrato de serviços de negócio para a entidade Projeto.
 */
class IProjetoService
{
public:
    /**
     * @brief Verifica autorização do papel logado para o serviço solicitado.
     * @param servico Identificador do serviço.
     * @return true quando a operação é permitida.
     */
    virtual bool autenticarPapel(ServicoEnum servico) = 0;

    /**
     * @brief Cria um novo projeto.
     * @param projeto Entidade de projeto a ser persistida.
     */
    virtual void criar(Projeto &projeto) = 0;

    /**
     * @brief Recupera um projeto pelo identificador.
     * @param id Chave primária do projeto.
     * @return Projeto encontrado.
     */
    virtual Projeto listarPorId(int id) = 0;

    /**
     * @brief Lista projetos cadastrados.
     * @return Coleção de projetos.
     */
    virtual std::list<Projeto> listar() = 0;

    /**
     * @brief Atualiza dados de um projeto.
     * @param projeto Entidade com alterações aplicadas.
     */
    virtual void atualizar(Projeto &projeto) = 0;

    /**
     * @brief Exclui um projeto pelo identificador.
     * @param id Chave primária do projeto.
     */
    virtual void excluir(int id) = 0;

    /**
     * @brief Lista projetos associados a uma pessoa.
     * @param pessoa Colaborador usado como filtro.
     * @return Coleção de projetos relacionados.
     */
    virtual std::list<Projeto> listarPorPessoa(Pessoa &pessoa) = 0;

    /**
     * @brief Destrutor virtual da interface de projeto.
     */
    virtual ~IProjetoService() = default;
};

#endif // IPROJETOSERVICE_HPP