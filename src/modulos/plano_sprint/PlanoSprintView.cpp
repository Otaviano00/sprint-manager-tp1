#include <modulos/plano_sprint/PlanoSprintView.hpp>
#include <modulos/plano_sprint/PlanoSprintService.hpp>
#include <modulos/plano_sprint/commands/CriarPlanoSprintCommand.hpp>
#include <modulos/plano_sprint/commands/ListarPlanoSprintCommand.hpp>
#include <modulos/plano_sprint/commands/AtualizarPlanoSprintCommand.hpp>
#include <modulos/plano_sprint/commands/ExcluirPlanoSprintCommand.hpp>
#include <core/PanelBuilder.hpp>
#include <util/ServicoEnum.hpp>
#include <iostream>

PlanoSprintView::PlanoSprintView()
{
    service = new PlanoSprintService();
}

PlanoSprintView::~PlanoSprintView()
{
    delete service;
}

Panel *PlanoSprintView::montarPainelCriar()
{
    if (service->autenticarPapel(S9_CRIAR_PLANO_SPRINT))
    {
        return PanelBuilder::builder()
            ->withTitle("Criar Plano de Sprint")
            ->withAction([this]()
                         { 
                             CriarPlanoSprintCommand cmd(this->service);
                             cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

Panel *PlanoSprintView::montarPainelListar()
{
    if (service->autenticarPapel(S10_LISTAR_PLANO_SPRINT))
    {
        return PanelBuilder::builder()
            ->withTitle("Listar Planos de Sprint")
            ->withAction([this]()
                         { 
                             ListarPlanoSprintCommand cmd(this->service);
                             cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

Panel *PlanoSprintView::montarPainelAtualizar()
{
    if (service->autenticarPapel(S11_ATUALIZAR_PLANO_SPRINT))
    {
        return PanelBuilder::builder()
            ->withTitle("Atualizar Plano de Sprint")
            ->withAction([this]()
                         { 
                             AtualizarPlanoSprintCommand cmd(this->service);
                             cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

Panel *PlanoSprintView::montarPainelExcluir()
{
    if (service->autenticarPapel(S12_EXCLUIR_PLANO_SPRINT))
    {
        return PanelBuilder::builder()
            ->withTitle("Excluir Plano de Sprint")
            ->withAction([this]()
                         { 
                             ExcluirPlanoSprintCommand cmd(this->service);
                             cmd.executar(); })
            ->withConfirmation(true)
            ->withEnd(true)
            ->build();
    }
    return nullptr;
}

void PlanoSprintView::executar()
{
    Panel *painelCriar = montarPainelCriar();
    Panel *painelListar = montarPainelListar();
    Panel *painelAtualizar = montarPainelAtualizar();
    Panel *painelExcluir = montarPainelExcluir();

    auto menuPrincipal = PanelBuilder::builder()
                             ->withTitle("Planos de Sprint")
                             ->build();

    if (painelCriar)
        menuPrincipal->addOption(painelCriar);
    if (painelListar)
        menuPrincipal->addOption(painelListar);
    if (painelAtualizar)
        menuPrincipal->addOption(painelAtualizar);
    if (painelExcluir)
        menuPrincipal->addOption(painelExcluir);

    menuPrincipal->showPanel();

    delete menuPrincipal;
    delete painelCriar;
    delete painelListar;
    delete painelAtualizar;
    delete painelExcluir;
}