#ifndef PLANOSPRINTVIEW_HPP
#define PLANOSPRINTVIEW_HPP

#include <modulos/plano_sprint/IPlanoSprintView.hpp>
#include <modulos/plano_sprint/IPlanoSprintService.hpp>
#include <core/Panel.hpp>

/**
 * @brief Implementa a interface CLI para operações de plano de sprint.
 */
class PlanoSprintView : public IPlanoSprintView
{
private:
    IPlanoSprintService *service;

public:
    /**
     * @brief Constrói o módulo de planos de sprint e inicializa dependências.
     */
    PlanoSprintView() = default;

    /**
     * @brief Exibe o menu de planos de sprint e executa ações selecionadas.
     */
    void executar() override;
};

#endif // PLANOSPRINTVIEW_HPP
