#include <modulos/historia_usuario/HistoriaUsuarioView.hpp>
#include <modulos/historia_usuario/HistoriaUsuarioService.hpp>
#include <modulos/historia_usuario/commands/CriarHistoriaCommand.hpp>
#include <modulos/historia_usuario/commands/ListarHistoriasCommand.hpp>
#include <modulos/historia_usuario/commands/ListarHistoriaProjetoCommand.hpp>
#include <modulos/historia_usuario/commands/ListarHistoriaPlanoSprintCommand.hpp>
#include <modulos/historia_usuario/commands/ListarHistoriaPessoaCommand.hpp>
#include <modulos/historia_usuario/commands/BuscarHistoriaCommand.hpp>
#include <modulos/historia_usuario/commands/AtualizarHistoriaCommand.hpp>
#include <modulos/historia_usuario/commands/ExcluirHistoriaCommand.hpp>
#include <modulos/historia_usuario/commands/AlterarEstadoHistoriaCommand.hpp>
#include <modulos/historia_usuario/commands/VincularHistoriaPessoaCommand.hpp>
#include <modulos/historia_usuario/commands/DesvincularHistoriaPessoaCommand.hpp>
#include <modulos/historia_usuario/commands/MoverHistoriaSprintCommand.hpp>
#include <core/PanelBuilder.hpp>
#include <iostream>

HistoriaUsuarioView::HistoriaUsuarioView()
{
    service = new HistoriaUsuarioService();
}

HistoriaUsuarioView::~HistoriaUsuarioView()
{
    delete service;
}

Panel *HistoriaUsuarioView::montarPainelCriar()
{
    if (service->autenticarPapel(S13_CRIAR_HISTORIA_USUARIO))
    {
        return PanelBuilder::builder()
            ->withTitle("Criar Historia de Usuario")
            ->withAction([this]()
                         { CriarHistoriaCommand cmd(this->service); cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

Panel *HistoriaUsuarioView::montarPainelListar()
{
    if (service->autenticarPapel(S14_LISTAR_HISTORIA_USUARIO))
    {
        Panel *painelListar = PanelBuilder::builder()
                                  ->withTitle("Listar Historias de Usuario")
                                  ->withOptions(true)
                                  ->withEnd(true)
                                  ->build();

        Panel *painelListarHistoriasDeUsuario = PanelBuilder::builder()
                                                    ->withTitle("Listar Historias de Usuario")
                                                    ->withAction([this]()
                                                                 { 
                                                           ListarHistoriasCommand cmd(this->service);
                                                           cmd.executar(); })
                                                    ->withEnd(true)
                                                    ->build();

        Panel *painelListarPorProjeto = PanelBuilder::builder()
                                            ->withTitle("Listar Historias de Usuario por Projeto")
                                            ->withOptions(true)
                                            ->withAction([this]()
                                                         { 
                                                            ListarHistoriaProjetoCommand cmd(this->service);
                                                            cmd.executar(); })
                                            ->withEnd(true)
                                            ->withConfirmation(true)
                                            ->build();

        Panel *painelListarPorPlanoSprint = PanelBuilder::builder()
                                                ->withTitle("Listar Historias de Usuario por Plano de Sprint")
                                                ->withOptions(true)
                                                ->withAction([this]()
                                                             { 
                                                            ListarHistoriaPlanoSprintCommand cmd(this->service);
                                                            cmd.executar(); })
                                                ->withEnd(true)
                                                ->withConfirmation(true)
                                                ->build();

        Panel *painelListarPorPessoa = PanelBuilder::builder()
                                           ->withTitle("Listar Historias de Usuario por Pessoa")
                                           ->withOptions(true)
                                           ->withAction([this]()
                                                        { 
                                                            ListarHistoriaPessoaCommand cmd(this->service);
                                                            cmd.executar(); })
                                           ->withEnd(true)
                                           ->withConfirmation(true)
                                           ->build();

        painelListar->addOption(painelListarHistoriasDeUsuario);
        painelListar->addOption(painelListarPorProjeto);
        painelListar->addOption(painelListarPorPlanoSprint);
        painelListar->addOption(painelListarPorPessoa);

        return painelListar;
    }
    return nullptr;
}

Panel *HistoriaUsuarioView::montarPainelBuscar()
{
    if (service->autenticarPapel(S14_LER_HISTORIA_USUARIO))
    {
        return PanelBuilder::builder()
            ->withTitle("Buscar Historia (Detalhes)")
            ->withAction([this]()
                         { BuscarHistoriaCommand cmd(this->service); cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

Panel *HistoriaUsuarioView::montarPainelAtualizar()
{
    if (service->autenticarPapel(S15_ATUALIZAR_HISTORIA_USUARIO))
    {
        return PanelBuilder::builder()
            ->withTitle("Atualizar Historia de Usuario")
            ->withAction([this]()
                         { AtualizarHistoriaCommand cmd(this->service); cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

Panel *HistoriaUsuarioView::montarPainelExcluir()
{
    if (service->autenticarPapel(S16_EXCLUIR_HISTORIA_USUARIO))
    {
        return PanelBuilder::builder()
            ->withTitle("Excluir Historia de Usuario")
            ->withAction([this]()
                         { ExcluirHistoriaCommand cmd(this->service); cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

Panel *HistoriaUsuarioView::montarPainelAlterarEstado()
{
    if (service->autenticarPapel(S25_ALTERAR_ESTADO_DE_HISTORIA_USUARIO))
    {
        return PanelBuilder::builder()
            ->withTitle("Alterar Estado da Historia")
            ->withAction([this]()
                         { AlterarEstadoHistoriaCommand cmd(this->service); cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

Panel *HistoriaUsuarioView::montarPainelVincular()
{
    if (service->autenticarPapel(S17_ESTABELECER_ASSOCIACAO_ENTRE_HU_E_PESSOA))
    {
        return PanelBuilder::builder()
            ->withTitle("Vincular Pessoa a Historia")
            ->withAction([this]()
                         { VincularHistoriaPessoaCommand cmd(this->service); cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

Panel *HistoriaUsuarioView::montarPainelDesvincular()
{
    if (service->autenticarPapel(S18_REMOVER_ASSOCIACAO_ENTRE_HU_E_PESSOA))
    {
        return PanelBuilder::builder()
            ->withTitle("Desvincular Pessoa da Historia")
            ->withAction([this]()
                         { DesvincularHistoriaPessoaCommand cmd(this->service); cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

Panel *HistoriaUsuarioView::montarPainelMover()
{
    if (service->autenticarPapel(S24_MOVER_HU_DE_PROJETO_PARA_PLANO_SPRINT))
    {
        return PanelBuilder::builder()
            ->withTitle("Mover Historia para Sprint")
            ->withAction([this]()
                         { MoverHistoriaSprintCommand cmd(this->service); cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

void HistoriaUsuarioView::executar()
{
    Panel *pCriar = montarPainelCriar();
    Panel *pListar = montarPainelListar();
    Panel *pBuscar = montarPainelBuscar();
    Panel *pAtualizar = montarPainelAtualizar();
    Panel *pExcluir = montarPainelExcluir();
    Panel *pEstado = montarPainelAlterarEstado();
    Panel *pVincular = montarPainelVincular();
    Panel *pDesvincular = montarPainelDesvincular();
    Panel *pMover = montarPainelMover();

    auto menu = PanelBuilder::builder()
                    ->withTitle("Gerenciar Historias de Usuario")
                    ->withOptions(true)
                    ->build();

    if (pCriar)
        menu->addOption(pCriar);
    if (pBuscar)
        menu->addOption(pBuscar);
    if (pListar)
        menu->addOption(pListar);
    if (pAtualizar)
        menu->addOption(pAtualizar);
    if (pEstado)
        menu->addOption(pEstado);
    if (pVincular)
        menu->addOption(pVincular);
    if (pDesvincular)
        menu->addOption(pDesvincular);
    if (pMover)
        menu->addOption(pMover);
    if (pExcluir)
        menu->addOption(pExcluir);

    menu->showPanel();

    delete menu;

    if (pCriar)
        delete pCriar;
    if (pListar)
        delete pListar;
    if (pBuscar)
        delete pBuscar;
    if (pAtualizar)
        delete pAtualizar;
    if (pExcluir)
        delete pExcluir;
    if (pEstado)
        delete pEstado;
    if (pVincular)
        delete pVincular;
    if (pDesvincular)
        delete pDesvincular;
    if (pMover)
        delete pMover;
}
