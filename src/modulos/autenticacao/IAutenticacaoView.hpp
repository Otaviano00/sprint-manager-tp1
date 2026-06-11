#ifndef IAUTENTICACAOVIEW_HPP
#define IAUTENTICACAOVIEW_HPP

/**
 * @brief Contrato da interface de apresentação para autenticação.
 */
class IAutenticacaoView
{
public:
    /**
     * @brief Exibe o fluxo de login via CLI.
     */
    virtual bool login() = 0;

    /**
     * @brief Exibe o fluxo de logout via CLI.
     */
    virtual bool logout() = 0;

    /**
     * @brief Destrutor virtual da interface de autenticação visual.
     */
    virtual ~IAutenticacaoView() = default;
};

#endif // IAUTENTICACAOVIEW_HPP