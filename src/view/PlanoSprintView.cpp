#include <view/PlanoSprintView.hpp>
#include <service/PlanoSprintService.hpp>
#include <iostream>

PlanoSprintView::PlanoSprintView()
{
    service = new PlanoSprintService();
    menuLocal = new JustOptionsPanel();
}

void PlanoSprintView::executar()
{
    menuLocal->addOption(new ActionPanel("Criar Plano de Sprint", [this]()
                                         { this->interfaceCriarPlanoSprint(); }));

    menuLocal->addOption(new ActionPanel("Listar Planos de Sprint", [this]()
                                         { this->interfaceListarPlanosSprint(); }));

    menuLocal->addOption(new ActionPanel("Listar Planos por Projeto", [this]()
                                         { this->interfaceListarPorProjeto(); }));

    menuLocal->addOption(new ActionPanel("Atualizar Plano de Sprint", [this]()
                                         { this->interfaceAtualizarPlanoSprint(); }));

    menuLocal->addOption(new ActionPanel("Excluir Plano de Sprint", [this]()
                                         { this->interfaceExcluirPlanoSprint(); }));

    menuLocal->showPanel();
}

void PlanoSprintView::interfaceCriarPlanoSprint()
{
}

void PlanoSprintView::interfaceListarPlanosSprint()
{
}

void PlanoSprintView::interfaceListarPorProjeto()
{
}

void PlanoSprintView::interfaceAtualizarPlanoSprint()
{
}

void PlanoSprintView::interfaceExcluirPlanoSprint()
{
}
