#include <view/AutenticacaoView.hpp>
#include <service/AutenticacaoService.hpp>
#include <iostream>

AutenticacaoView::AutenticacaoView()
{
    service = AutenticacaoService::getInstance();
    menuLocal = new JustOptionsPanel();
}

void AutenticacaoView::executar()
{
    menuLocal->addOption(new ActionPanel("Realizar Login", [this]()
                                         { this->interfaceLogin(); }));

    menuLocal->addOption(new ActionPanel("Desconectar (Logout)", [this]()
                                         { this->interfaceLogout(); }));

    menuLocal->showPanel();
}

void AutenticacaoView::interfaceLogin()
{
}

void AutenticacaoView::interfaceLogout()
{
}
