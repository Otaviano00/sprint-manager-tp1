#ifndef IAUTENTICACAOVIEW_HPP
#define IAUTENTICACAOVIEW_HPP

/**
 * @brief Contrato da interface de apresentação para autenticação.
 */
class IAutenticacaoView
{
public:
    /**
     * @brief Exibe o fluxo de autenticação (login/logout) via CLI.
     */
    virtual void executar() = 0;

    /**
     * @brief Destrutor virtual da interface de autenticação visual.
     */
    virtual ~IAutenticacaoView() = default;
};

#endif // IAUTENTICACAOVIEW_HPP