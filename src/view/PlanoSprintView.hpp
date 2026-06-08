#ifndef PLANOSPRINTVIEW_HPP
#define PLANOSPRINTVIEW_HPP

#include <view/IPlanoSprintView.hpp>
#include <service/IPlanoSprintService.hpp>
#include <panel/Panel.hpp>

/**
 * @brief Implementa a interface CLI para operações de plano de sprint.
 */
class PlanoSprintView : public IPlanoSprintView
{
private:
    IPlanoSprintService *service;
    JustOptionsPanel *menuLocal;

    void interfaceCriarPlanoSprint();
    void interfaceListarPlanosSprint();
    void interfaceAtualizarPlanoSprint();
    void interfaceExcluirPlanoSprint();
    void interfaceListarPorProjeto();

public:
    /**
     * @brief Constrói o módulo de planos de sprint e inicializa dependências.
     */
    PlanoSprintView();

    /**
     * @brief Exibe o menu de planos de sprint e executa ações selecionadas.
     */
    void executar() override;
};

#endif // PLANOSPRINTVIEW_HPP
