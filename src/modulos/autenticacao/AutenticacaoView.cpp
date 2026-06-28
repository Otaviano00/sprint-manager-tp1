#include <modulos/autenticacao/AutenticacaoView.hpp>
#include <modulos/autenticacao/AutenticacaoService.hpp>
#include <modulos/pessoa/PessoaService.hpp>
#include <modulos/autenticacao/commands/LoginCommand.hpp>
#include <modulos/autenticacao/commands/PrimeiroAcessoCommand.hpp>
#include <modulos/autenticacao/commands/LogoutCommand.hpp>
#include <core/PanelBuilder.hpp>
#include <util/ViewUtils.hpp>
#include <iostream>

AutenticacaoView::AutenticacaoView()
{
    service = AutenticacaoService::getInstance();
    pessoaService = new PessoaService();
}

AutenticacaoView::~AutenticacaoView()
{
    delete pessoaService;
}

void showLogo()
{
    ViewUtils::clear();
    if (ViewUtils::printTextFile("logo.txt"))
    {
        return;
    }
}

Panel *AutenticacaoView::montarPainelLogin()
{
    return PanelBuilder::builder()
        ->withTitle("Login")
        ->withAction([this]()
                     { 
                         LoginCommand cmd(this->service);
                         cmd.executar(); })
        ->withEnd(true)
        ->build();
}

Panel *AutenticacaoView::montarPainelPrimeiroAcesso()
{
    return PanelBuilder::builder()
        ->withTitle("Primeiro Acesso - Criar Conta")
        ->withAction([this]()
                     { 
                         PrimeiroAcessoCommand cmd(this->service, this->pessoaService);
                         cmd.executar(); })
        ->withEnd(true)
        ->build();
}

Panel *AutenticacaoView::montarPainelLogout()
{
    return PanelBuilder::builder()
        ->withInitialCleanScreen(false)
        ->withAction([this]()
                     { 
                         LogoutCommand cmd(this->service);
                         cmd.executar(); })
        ->withZeroAction(false)
        ->withConfirmation(false)
        ->withEnd(true)
        ->build();
}

bool AutenticacaoView::login()
{
    querSair = false;

    Panel *panelLogin = montarPainelLogin();
    Panel *panelPrimeiroAcesso = montarPainelPrimeiroAcesso();

    auto panelEntrada = PanelBuilder::builder()
                            ->withInitialCleanScreen(false)
                            ->withOptions(true)
                            ->withAction([this]()
                                         { showLogo(); })
                            ->withZeroAction(true, "Sair", [this]()
                                             { querSair = true; })
                            ->withExitCondition([this]()
                                                { return this->service->isLoggedIn() || this->getQuerSair(); })
                            ->build();

    if (panelLogin)
        panelEntrada->addOption(panelLogin);
    if (panelPrimeiroAcesso)
        panelEntrada->addOption(panelPrimeiroAcesso);

    panelEntrada->showPanel();

    delete panelEntrada;
    delete panelLogin;
    delete panelPrimeiroAcesso;

    return service->isLoggedIn();
}

bool AutenticacaoView::logout()
{
    Panel *panelLogout = montarPainelLogout();

    if (panelLogout)
    {
        panelLogout->showPanel();
        delete panelLogout;
    }

    return !service->isLoggedIn();
}

bool AutenticacaoView::getQuerSair()
{
    return querSair;
}
