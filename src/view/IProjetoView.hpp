#ifndef IPROJETOVIEW_HPP
#define IPROJETOVIEW_HPP

/**
 * @brief Contrato da interface de apresentação para Projeto.
 */
class IProjetoView
{
public:
    /**
     * @brief Exibe o painel de gerenciamento de projetos.
     */
    virtual void executar() = 0;

    /**
     * @brief Destrutor virtual da interface de projeto visual.
     */
    virtual ~IProjetoView() = default;
};

#endif // IPROJETOVIEW_HPP
