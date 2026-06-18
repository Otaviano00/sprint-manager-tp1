#include <modulos/mvc/ViewController.hpp>
#include <modulos/historia_usuario/HistoriaUsuarioView.hpp>
#include <modulos/autenticacao/AutenticacaoView.hpp>
#include <modulos/pessoa/PessoaView.hpp>
#include <modulos/projeto/ProjetoView.hpp>
#include <modulos/plano_sprint/PlanoSprintView.hpp>
#include <core/Panel.hpp>
#include <core/PanelBuilder.hpp>
#include <util/ViewUtils.hpp>
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

void showLogo()
{
    if (ViewUtils::printTextFile("logo.txt"))
    {
        return;
    }
}

void ViewController::executar()
{

    auto menuPrincipal = PanelBuilder::builder()
                             ->withTitle("Menu Principal")
                             ->withOptions(true)
                             ->withZeroAction(true, "Logout", [this]()
                                              { this->autenticacaoView->logout(); })
                             ->build();

    auto menuPessoas = PanelBuilder::builder()
                           ->withTitle("Gerenciar Pessoas")
                           ->withAction([this]()
                                        { std::cout << "Funcionalidade em desenvolvimento." << std::endl; })
                           ->withEnd(true) // temporário para teste de fluxo
                           ->build();

    menuPrincipal->addOption(menuPessoas);

    auto menuProjetos = PanelBuilder::builder()
                            ->withTitle("Gerenciar Projetos")
                            ->withAction([this]()
                                         { this->projetoView->executar(); })
                            ->withEnd(true)
                            ->build();

    menuPrincipal->addOption(menuProjetos);

    auto menuHistoriasUsuario = PanelBuilder::builder()
                                    ->withTitle("Gerenciar Historias de Usuario")
                                    ->withAction([this]()
                                                 { std::cout << "Funcionalidade em desenvolvimento." << std::endl; })
                                    ->withEnd(true) // temporário para teste de fluxo
                                    ->build();

    menuPrincipal->addOption(menuHistoriasUsuario);

    auto menuPlanosSprint = PanelBuilder::builder()
                                ->withTitle("Gerenciar Planos de Sprint")
                                ->withAction([this]()
                                             { std::cout << "Funcionalidade em desenvolvimento." << std::endl; })
                                ->withEnd(true) // temporário para teste de fluxo
                                ->build();

    menuPrincipal->addOption(menuPlanosSprint);

    while (true)
    {
        ViewUtils::clear();
        showLogo();
        if (!autenticacaoView->login())
        {
            continue;
        }

        menuPrincipal->showPanel();
    }
    delete menuPrincipal;
}