#include <modulos/autenticacao/AutenticacaoView.hpp>
#include <modulos/autenticacao/AutenticacaoService.hpp>
#include <iostream>
#include <core/PanelBuilder.hpp>

AutenticacaoView::AutenticacaoView()
{
    service = AutenticacaoService::getInstance();
}

void AutenticacaoView::interfaceLogin()
{
    std::string email, senha;

    std::cout << "Digite seu email: ";
    std::getline(std::cin, email);

    std::cout << "Digite sua senha: ";
    std::getline(std::cin, senha);

    if (service->login(email, senha))
    {
        std::cout << std::endl
                  << "Login bem-sucedido!" << std::endl;
    }
    else
    {
        throw std::invalid_argument("Email ou senha não encontrados.");
    }
}

void AutenticacaoView::interfaceLogout()
{
    service->logout();
    std::cout << "Logout realizado com sucesso!" << std::endl;
}

bool AutenticacaoView::login()
{
    auto panelLogin = PanelBuilder::builder()
                          ->withAction([this]()
                                       { this->interfaceLogin(); })
                          ->withZeroAction(false)
                          ->withEnd(true)
                          ->build();

    panelLogin->showPanel(false);
    delete panelLogin;

    return service->isLoggedIn();
}

bool AutenticacaoView::logout()
{
    auto panelLogout = PanelBuilder::builder()
                           ->withAction([this]()
                                        { this->interfaceLogout(); })
                           ->withZeroAction(false)
                           ->withEnd(true)
                           ->build();

    panelLogout->showPanel();
    delete panelLogout;

    return !service->isLoggedIn();
}
