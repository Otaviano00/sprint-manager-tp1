#include <modulos/mvc/ViewController.hpp>
#include <modulos/historia_usuario/HistoriaUsuarioView.hpp>
#include <modulos/autenticacao/AutenticacaoView.hpp>
#include <modulos/pessoa/PessoaView.hpp>
#include <modulos/projeto/ProjetoView.hpp>
#include <modulos/plano_sprint/PlanoSprintView.hpp>
#include <core/Panel.hpp>
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