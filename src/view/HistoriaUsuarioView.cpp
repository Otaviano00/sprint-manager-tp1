#include <view/HistoriaUsuarioView.hpp>
#include <service/HistoriaUsuarioService.hpp>
#include <iostream>

HistoriaUsuarioView::HistoriaUsuarioView()
{
    service = new HistoriaUsuarioService();
    menuLocal = new JustOptionsPanel();
}

void HistoriaUsuarioView::executar()
{
    menuLocal->addOption(new ActionPanel("Criar Nova História de Usuário", [this]()
                                         { this->interfaceCriarHistoria(); }));

    menuLocal->addOption(new ActionPanel("Listar Histórias do Projeto", [this]()
                                         { this->interfaceListarHistorias(); }));

    menuLocal->showPanel();
}

void HistoriaUsuarioView::interfaceCriarHistoria()
{
}

void HistoriaUsuarioView::interfaceListarHistorias()
{
}