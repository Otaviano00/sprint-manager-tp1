#ifndef PLANOSPRINTVIEW_HPP
#define PLANOSPRINTVIEW_HPP

#include <view/IPlanoSprintView.hpp>
#include <service/IPlanoSprintService.hpp>
#include <panel/Panel.hpp>

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
    PlanoSprintView();

    void executar() override;
};

#endif // PLANOSPRINTVIEW_HPP
