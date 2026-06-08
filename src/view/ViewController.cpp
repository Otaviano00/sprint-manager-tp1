#include <view/ViewController.hpp>
#include <view/HistoriaUsuarioView.hpp>
#include <view/AutenticacaoView.hpp>
#include <view/PessoaView.hpp>
#include <view/ProjetoView.hpp>
#include <view/PlanoSprintView.hpp>
#include <panel/Panel.hpp>
#include <iostream>

ViewController::ViewController()
{
    historiaView = new HistoriaUsuarioView();
    autenticacaoView = new AutenticacaoView();
    pessoaView = new PessoaView();
    projetoView = new ProjetoView();
    planoSprintView = new PlanoSprintView();
}

ViewController::~ViewController()
{
    delete historiaView;
    delete autenticacaoView;
    delete pessoaView;
    delete projetoView;
    delete planoSprintView;
}

void ViewController::executar()
{
    auto menuPrincipal = new Panel("Menu Principal", false, true);

    menuPrincipal->addOption(new ActionPanel("Autenticação / Login", [this]()
                                             { this->autenticacaoView->executar(); }));

    menuPrincipal->addOption(new ActionPanel("Gerenciar Pessoas", [this]()
                                             { this->pessoaView->executar(); }));

    menuPrincipal->addOption(new ActionPanel("Gerenciar Projetos", [this]()
                                             { this->projetoView->executar(); }));

    menuPrincipal->addOption(new ActionPanel("Histórias de Usuário", [this]()
                                             { this->historiaView->executar(); }));

    menuPrincipal->addOption(new ActionPanel("Planos de Sprint", [this]()
                                             { this->planoSprintView->executar(); }));

    menuPrincipal->showPanel();

    delete menuPrincipal;
}