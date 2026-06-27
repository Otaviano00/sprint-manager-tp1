#include <modulos/projeto/ProjetoView.hpp>
#include <modulos/projeto/ProjetoService.hpp>
#include <modulos/projeto/commands/CriarProjetoCommand.hpp>
#include <modulos/projeto/commands/ListarProjetosCommand.hpp>
#include <modulos/projeto/commands/BuscarProjetoCommand.hpp>
#include <modulos/projeto/commands/AtualizarProjetoCommand.hpp>
#include <modulos/projeto/commands/ExcluirProjetoCommand.hpp>
#include <core/PanelBuilder.hpp>
#include <iostream>
#include <string>

ProjetoView::ProjetoView()
{
    service = new ProjetoService();
}

ProjetoView::~ProjetoView()
{
    delete service;
}

void ProjetoView::executar()
{
    Panel *painelCriar = nullptr;
    if (service->autenticarPapel(S5_CRIAR_PROJETO))
    {
        painelCriar = PanelBuilder::builder()
                          ->withTitle("Cadastrar Projeto")
                          ->withAction([this]()
                                       { 
                                           CriarProjetoCommand cmd(this->service);
                                           cmd.executar(); })
                          ->withEnd(true)
                          ->build();
    }

    Panel *painelListar = nullptr;
    if (service->autenticarPapel(S6_LER_PROJETO))
    {
        painelListar = PanelBuilder::builder()
                           ->withTitle("Listar Projetos")
                           ->withAction([this]()
                                        { 
                                            ListarProjetosCommand cmd(this->service);
                                            cmd.executar(); })
                           ->withEnd(true)
                           ->build();
    }

    Panel *painelBuscar = nullptr;
    if (service->autenticarPapel(S6_LER_PROJETO))
    {
        painelBuscar = PanelBuilder::builder()
                           ->withTitle("Buscar Projeto")
                           ->withAction([this]()
                                        { 
                                            BuscarProjetoCommand cmd(this->service);
                                            cmd.executar(); })
                           ->withEnd(true)
                           ->build();
    }

    Panel *painelAtualizar = nullptr;
    if (service->autenticarPapel(S7_ATUALIZAR_PROJETO))
    {
        painelAtualizar = PanelBuilder::builder()
                              ->withTitle("Atualizar Projeto")
                              ->withAction([this]()
                                           { 
                                               AtualizarProjetoCommand cmd(this->service);
                                               cmd.executar(); })
                              ->withEnd(true)
                              ->build();
    }

    Panel *painelExcluir = nullptr;
    if (service->autenticarPapel(S8_EXCLUIR_PROJETO))
    {
        painelExcluir = PanelBuilder::builder()
                            ->withTitle("Excluir Projeto")
                            ->withAction([this]()
                                         { 
                                             ExcluirProjetoCommand cmd(this->service);
                                             cmd.executar(); })
                            ->withEnd(true)
                            ->build();
    }

    auto painelProjetos = PanelBuilder::builder()
                              ->withTitle("Gerenciar Projetos")
                              ->withOptions(true)
                              ->withZeroAction(true, "Voltar")
                              ->build();

    if (painelCriar != nullptr)
        painelProjetos->addOption(painelCriar);
    if (painelListar != nullptr)
        painelProjetos->addOption(painelListar);
    if (painelBuscar != nullptr)
        painelProjetos->addOption(painelBuscar);
    if (painelAtualizar != nullptr)
        painelProjetos->addOption(painelAtualizar);
    if (painelExcluir != nullptr)
        painelProjetos->addOption(painelExcluir);

    painelProjetos->showPanel();

    delete painelProjetos;
    delete painelCriar;
    delete painelListar;
    delete painelBuscar;
    delete painelAtualizar;
    delete painelExcluir;
}
