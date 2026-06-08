#ifndef IPLANOSPRINTVIEW_HPP
#define IPLANOSPRINTVIEW_HPP

/**
 * @brief Contrato da interface de apresentação para Plano de Sprint.
 */
class IPlanoSprintView
{
public:
    /**
     * @brief Exibe o painel de gerenciamento de planos de sprint.
     */
    virtual void executar() = 0;

    /**
     * @brief Destrutor virtual da interface de plano de sprint visual.
     */
    virtual ~IPlanoSprintView() = default;
};

#endif // IPLANOSPRINTVIEW_HPP
