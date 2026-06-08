#ifndef IPESSOAVIEW_HPP
#define IPESSOAVIEW_HPP

/**
 * @brief Contrato da interface de apresentação para Pessoa.
 */
class IPessoaView
{
public:
    /**
     * @brief Exibe o painel de gerenciamento de pessoas.
     */
    virtual void executar() = 0;

    /**
     * @brief Destrutor virtual da interface de pessoa visual.
     */
    virtual ~IPessoaView() = default;
};

#endif // IPESSOAVIEW_HPP
