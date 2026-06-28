#include <modulos/projeto/ProjetoView.hpp>
#include <modulos/projeto/ProjetoService.hpp>
#include <modulos/projeto/commands/CriarProjetoCommand.hpp>
#include <modulos/projeto/commands/ListarProjetosCommand.hpp>
#include <modulos/projeto/commands/BuscarProjetoCommand.hpp>
#include <modulos/projeto/commands/AtualizarProjetoCommand.hpp>
#include <modulos/projeto/commands/ExcluirProjetoCommand.hpp>
#include <modulos/projeto/commands/ListarProjetosPessoaCommand.hpp>
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

Panel *ProjetoView::montarPainelCriar()
{
    if (service->autenticarPapel(S5_CRIAR_PROJETO))
    {
        return PanelBuilder::builder()
            ->withTitle("Cadastrar Projeto")
            ->withAction([this]()
                         { 
                             CriarProjetoCommand cmd(this->service);
                             cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

Panel *ProjetoView::montarPainelListar()
{
    if (service->autenticarPapel(S6_LER_PROJETO))
    {
        Panel *painelListar = PanelBuilder::builder()
                                  ->withTitle("Listar Projetos")
                                  ->withOptions(true)
                                  ->withEnd(true)
                                  ->build();

        Panel *painelListarProjetos = PanelBuilder::builder()
                                          ->withTitle("Listar Projetos")
                                          ->withAction([this]()
                                                       { 
                                                           ListarProjetosCommand cmd(this->service);
                                                           cmd.executar(); })
                                          ->withEnd(true)
                                          ->build();

        Panel *painelListarPorPessoa = PanelBuilder::builder()
                                           ->withTitle("Listar Projetos de uma Pessoa")
                                           ->withOptions(true)
                                           ->withAction([this]()
                                                        { 
                                                            ListarProjetosPessoaCommand cmd(this->service);
                                                            cmd.executar(); })
                                           ->withEnd(true)
                                           ->withConfirmation(true)
                                           ->build();

        painelListar->addOption(painelListarPorPessoa);
        painelListar->addOption(painelListarProjetos);

        return painelListar;
    }
    return nullptr;
}

Panel *ProjetoView::montarPainelBuscar()
{
    if (service->autenticarPapel(S6_LER_PROJETO))
    {
        return PanelBuilder::builder()
            ->withTitle("Buscar Projeto")
            ->withAction([this]()
                         { 
                             BuscarProjetoCommand cmd(this->service);
                             cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

Panel *ProjetoView::montarPainelAtualizar()
{
    if (service->autenticarPapel(S7_ATUALIZAR_PROJETO))
    {
        return PanelBuilder::builder()
            ->withTitle("Atualizar Projeto")
            ->withAction([this]()
                         { 
                             AtualizarProjetoCommand cmd(this->service);
                             cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

Panel *ProjetoView::montarPainelExcluir()
{
    if (service->autenticarPapel(S8_EXCLUIR_PROJETO))
    {
        return PanelBuilder::builder()
            ->withTitle("Excluir Projeto")
            ->withAction([this]()
                         { 
                             ExcluirProjetoCommand cmd(this->service);
                             cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

void ProjetoView::executar()
{
    Panel *painelCriar = montarPainelCriar();
    Panel *painelListar = montarPainelListar();
    Panel *painelBuscar = montarPainelBuscar();
    Panel *painelAtualizar = montarPainelAtualizar();
    Panel *painelExcluir = montarPainelExcluir();

    auto painelProjetos = PanelBuilder::builder()
                              ->withTitle("Gerenciar Projetos")
                              ->withOptions(true)
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
