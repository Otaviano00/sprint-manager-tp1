#ifndef IHISTORIAUSUARIOVIEW_HPP
#define IHISTORIAUSUARIOVIEW_HPP

/**
 * @brief Contrato da interface de apresentação para História de Usuário.
 */
class IHistoriaUsuarioView
{
public:
    /**
     * @brief Exibe o painel de gerenciamento de histórias de usuário.
     */
    virtual void executar() = 0;

    /**
     * @brief Destrutor virtual da interface de história de usuário visual.
     */
    virtual ~IHistoriaUsuarioView() = default;
};

#endif // IHISTORIAUSUARIOVIEW_HPP