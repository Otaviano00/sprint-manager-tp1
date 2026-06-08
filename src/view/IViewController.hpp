#ifndef IVIEWCONTROLLER_HPP
#define IVIEWCONTROLLER_HPP

/**
 * @brief Contrato do controlador principal de navegação da aplicação.
 */
class IViewController
{
public:
    /**
     * @brief Inicia o fluxo principal de telas da aplicação.
     */
    virtual void executar() = 0;

    /**
     * @brief Destrutor virtual da interface de controlador.
     */
    virtual ~IViewController() = default;
};

#endif // IVIEWCONTROLLER_HPP