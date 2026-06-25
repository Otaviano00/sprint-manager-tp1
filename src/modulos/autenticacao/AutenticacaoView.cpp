#include <modulos/autenticacao/AutenticacaoView.hpp>
#include <modulos/autenticacao/AutenticacaoService.hpp>
#include <modulos/pessoa/PessoaService.hpp>
#include <modulos/pessoa/Pessoa.hpp>
#include <dominios/Email.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Senha.hpp>
#include <dominios/Papel.hpp>
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

void AutenticacaoView::interfacePrimeiroAcesso()
{
    std::string nomeStr, emailStr, senhaStr, papelStr;

    std::cout << "Nome: ";
    std::getline(std::cin, nomeStr);

    std::cout << "Email: ";
    std::getline(std::cin, emailStr);

    std::cout << "Senha: ";
    std::getline(std::cin, senhaStr);

    std::cout << "Papel (DESENVOLVEDOR / MESTRE_SCRUM / PROPRIETARIO_DE_PRODUTO): ";
    std::getline(std::cin, papelStr);

    Pessoa pessoa;

    Nome nome;
    nome.setValor(nomeStr);
    pessoa.setNome(nome);

    Email email;
    email.setValor(emailStr);
    pessoa.setEmail(email);

    Senha senha;
    senha.setValor(senhaStr);
    pessoa.setSenha(senha);

    Papel papel;
    papel.setValor(papelStr);
    pessoa.setPapel(papel);

    pessoaService->criar(pessoa);

    std::cout << std::endl
              << "Conta criada com sucesso! Faça login para continuar." << std::endl;
}

void AutenticacaoView::interfaceLogout()
{
    service->logout();
    std::cout << std::endl
              << "Logout realizado com sucesso!" << std::endl;
}

bool AutenticacaoView::login()
{
    _querSair = false;

    auto panelLogin = PanelBuilder::builder()
                          ->withTitle("Login")
                          ->withAction([this]()
                                       { this->interfaceLogin(); })
                          ->withEnd(true)
                          ->build();

    auto panelPrimeiroAcesso = PanelBuilder::builder()
                                   ->withTitle("Primeiro Acesso - Criar Conta")
                                   ->withAction([this]()
                                                { this->interfacePrimeiroAcesso(); })
                                   ->withEnd(true)
                                   ->build();

    auto panelEntrada = PanelBuilder::builder()
                            ->withInitialCleanScreen(false)
                            ->withOptions(true)
                            ->withAction([this]()
                                         { showLogo(); })
                            ->withZeroAction(true, "Sair", [this]()
                                             { _querSair = true; })
                            ->withExitCondition([this]()
                                                { return this->service->isLoggedIn() || this->_querSair; })
                            ->build();

    panelEntrada->addOption(panelLogin);
    panelEntrada->addOption(panelPrimeiroAcesso);

    panelEntrada->showPanel();

    delete panelEntrada;
    delete panelLogin;
    delete panelPrimeiroAcesso;

    return service->isLoggedIn();
}

bool AutenticacaoView::logout()
{
    auto panelLogout = PanelBuilder::builder()
                           ->withInitialCleanScreen(false)
                           ->withAction([this]()
                                        { this->interfaceLogout(); })
                           ->withZeroAction(false)
                           ->withConfirmation(false)
                           ->withEnd(true)
                           ->build();

    panelLogout->showPanel();
    delete panelLogout;

    return !service->isLoggedIn();
}

bool AutenticacaoView::querSair()
{
    return _querSair;
}
