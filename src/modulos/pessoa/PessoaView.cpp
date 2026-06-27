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

void PessoaView::executar()
{
    Panel *painelCriar = nullptr;
    if (service->autenticarPapel(S1_CRIAR_PESSOA))
    {
        painelCriar = PanelBuilder::builder()
                          ->withTitle("Cadastrar Pessoa")
                          ->withAction([this]()
                                       { 
                                           CriarPessoaCommand cmd(this->service);
                                           cmd.executar(); 
                                       })
                          ->withEnd(true)
                          ->build();
    }

    Panel *painelListar = nullptr;
    if (service->autenticarPapel(S2_LISTAR_PESSOA))
    {
        painelListar = PanelBuilder::builder()
                           ->withTitle("Listar Pessoas")
                           ->withAction([this]()
                                        { 
                                            ListarPessoasCommand cmd(this->service);
                                            cmd.executar();
                                        })
                           ->withEnd(true)
                           ->build();
    }

    Panel *painelBuscar = nullptr;
    if (service->autenticarPapel(S2_LER_PESSOA))
    {
        painelBuscar = PanelBuilder::builder()
                           ->withTitle("Buscar Pessoa")
                           ->withAction([this]()
                                        { 
                                            BuscarPessoaCommand cmd(this->service);
                                            cmd.executar();
                                        })
                           ->withEnd(true)
                           ->build();
    }

    Panel *painelAtualizar = nullptr;
    if (service->autenticarPapel(S3_ATUALIZAR_PESSOA))
    {
        painelAtualizar = PanelBuilder::builder()
                              ->withTitle("Atualizar Pessoa")
                              ->withAction([this]()
                                           { 
                                               AtualizarPessoaCommand cmd(this->service);
                                               cmd.executar();
                                           })
                              ->withEnd(true)
                              ->build();
    }

    Panel *painelExcluir = nullptr;
    if (service->autenticarPapel(S4_EXCLUIR_PESSOA))
    {
        painelExcluir = PanelBuilder::builder()
                            ->withTitle("Excluir Pessoa")
                            ->withAction([this]()
                                         { 
                                             ExcluirPessoaCommand cmd(this->service);
                                             cmd.executar();
                                         })
                            ->withEnd(true)
                            ->build();
    }

    auto painelPessoas = PanelBuilder::builder()
                             ->withTitle("Gerenciar Pessoas")
                             ->withOptions(true)
                             ->withZeroAction(true, "Voltar")
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
