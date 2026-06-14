#ifndef PESSOAVIEW_HPP
#define PESSOAVIEW_HPP

#include <modulos/pessoa/IPessoaView.hpp>
#include <modulos/pessoa/IPessoaService.hpp>
#include <core/Panel.hpp>

/**
 * @brief Interface de apresentação do módulo Pessoa.
 *
 * Responsável por interagir com o usuário através do terminal,
 * coletando dados e acionando os serviços da camada de negócio.
 */
class PessoaView : public IPessoaView
{
private:
    /**
     * @brief Serviço responsável pelas regras de negócio.
     */
    IPessoaService *service;

    /**
     * @brief Fluxo de criação de pessoa.
     */
    void criarPessoa();

    /**
     * @brief Fluxo de listagem de pessoas.
     */
    void listarPessoas();

    /**
     * @brief Fluxo de atualização de pessoa.
     */
    void atualizarPessoa();

    /**
     * @brief Fluxo de exclusão de pessoa.
     */
    void excluirPessoa();

public:
    /**
     * @brief Constrói a view e inicializa o serviço.
     */
    PessoaView();

    /**
     * @brief Exibe o menu principal do módulo Pessoa.
     */
    void executar() override;

    /**
     * @brief Destrutor da view.
     */
    ~PessoaView();
};

#endif // PESSOAVIEW_HPP