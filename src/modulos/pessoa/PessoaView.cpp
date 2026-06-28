#include <modulos/pessoa/PessoaView.hpp>
#include <modulos/pessoa/PessoaService.hpp>
#include <modulos/pessoa/commands/CriarPessoaCommand.hpp>
#include <modulos/pessoa/commands/ListarPessoasCommand.hpp>
#include <modulos/pessoa/commands/BuscarPessoaCommand.hpp>
#include <modulos/pessoa/commands/AtualizarPessoaCommand.hpp>
#include <modulos/pessoa/commands/ExcluirPessoaCommand.hpp>
#include <core/PanelBuilder.hpp>
#include <iostream>
#include <string>

PessoaView::PessoaView()
{
    service = new PessoaService();
}

PessoaView::~PessoaView()
{
    delete service;
}

Panel *PessoaView::montarPainelCriar()
{
    if (service->autenticarPapel(S1_CRIAR_PESSOA))
    {
        return PanelBuilder::builder()
            ->withTitle("Cadastrar Pessoa")
            ->withAction([this]()
                         { 
                             CriarPessoaCommand cmd(this->service);
                             cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

Panel *PessoaView::montarPainelListar()
{
    if (service->autenticarPapel(S2_LISTAR_PESSOA))
    {
        return PanelBuilder::builder()
            ->withTitle("Listar Pessoas")
            ->withAction([this]()
                         { 
                             ListarPessoasCommand cmd(this->service);
                             cmd.executar(); })
            ->withEnd(true)
            ->build();
    }
    return nullptr;
}

Panel *PessoaView::montarPainelBuscar()
{
    if (service->autenticarPapel(S2_LER_PESSOA))
    {
        return PanelBuilder::builder()
            ->withTitle("Buscar Pessoa")
            ->withAction([this]()
                         { 
                             BuscarPessoaCommand cmd(this->service);
                             cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

Panel *PessoaView::montarPainelAtualizar()
{
    if (service->autenticarPapel(S3_ATUALIZAR_PESSOA))
    {
        return PanelBuilder::builder()
            ->withTitle("Atualizar Pessoa")
            ->withAction([this]()
                         { 
                             AtualizarPessoaCommand cmd(this->service);
                             cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

Panel *PessoaView::montarPainelExcluir()
{
    if (service->autenticarPapel(S4_EXCLUIR_PESSOA))
    {
        return PanelBuilder::builder()
            ->withTitle("Excluir Pessoa")
            ->withAction([this]()
                         { 
                             ExcluirPessoaCommand cmd(this->service);
                             cmd.executar(); })
            ->withEnd(true)
            ->withConfirmation(true)
            ->build();
    }
    return nullptr;
}

void PessoaView::executar()
{
    Panel *painelCriar = montarPainelCriar();
    Panel *painelListar = montarPainelListar();
    Panel *painelBuscar = montarPainelBuscar();
    Panel *painelAtualizar = montarPainelAtualizar();
    Panel *painelExcluir = montarPainelExcluir();

    auto painelPessoas = PanelBuilder::builder()
                             ->withTitle("Gerenciar Pessoas")
                             ->withOptions(true)
                             ->build();

    if (painelCriar != nullptr)
        painelPessoas->addOption(painelCriar);
    if (painelListar != nullptr)
        painelPessoas->addOption(painelListar);
    if (painelBuscar != nullptr)
        painelPessoas->addOption(painelBuscar);
    if (painelAtualizar != nullptr)
        painelPessoas->addOption(painelAtualizar);
    if (painelExcluir != nullptr)
        painelPessoas->addOption(painelExcluir);

    painelPessoas->showPanel();

    delete painelPessoas;
    delete painelCriar;
    delete painelListar;
    delete painelBuscar;
    delete painelAtualizar;
    delete painelExcluir;
}
