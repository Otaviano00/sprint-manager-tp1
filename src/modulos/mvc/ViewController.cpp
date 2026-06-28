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

void ViewController::executar()
{

    auto menuPrincipal = PanelBuilder::builder()
                             ->withTitle("Menu Principal")
                             ->withOptions(true)
                             ->withZeroAction(true, "Logout", [this]()
                                              { this->autenticacaoView->logout(); }, true)
                             ->build();

    auto menuPessoas = PanelBuilder::builder()
                           ->withTitle("Gerenciar Pessoas")
                           ->withAction([this]()
                                        { this->pessoaView->executar(); })
                           ->withEnd(true)
                           ->build();

    auto menuProjetos = PanelBuilder::builder()
                            ->withTitle("Gerenciar Projetos")
                            ->withAction([this]()
                                         { this->projetoView->executar(); })
                            ->withEnd(true)
                            ->build();

    auto menuHistoriasUsuario = PanelBuilder::builder()
                                    ->withTitle("Gerenciar Historias de Usuario")
                                    ->withAction([this]()
                                                 { this->historiaView->executar(); })
                                    ->withEnd(true)
                                    ->build();

    auto menuPlanosSprint = PanelBuilder::builder()
                                ->withTitle("Gerenciar Planos de Sprint")
                                ->withAction([this]()
                                             { std::cout << "Funcionalidade em desenvolvimento." << std::endl; })
                                ->withEnd(true) // temporário para teste de fluxo
                                ->build();

    menuPrincipal->addOption(menuPessoas);
    menuPrincipal->addOption(menuProjetos);
    menuPrincipal->addOption(menuHistoriasUsuario);
    menuPrincipal->addOption(menuPlanosSprint);

    while (true)
    {
        autenticacaoView->login();

        if (autenticacaoView->getQuerSair())
            break;

        menuPrincipal->showPanel();
    }

    std::cout << std::endl
              << "Encerrando o sistema... " << std::endl;

    delete menuPrincipal;
}