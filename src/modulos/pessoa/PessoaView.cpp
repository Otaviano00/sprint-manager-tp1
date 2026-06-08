#include <modulos/pessoa/PessoaView.hpp>
#include <modulos/pessoa/PessoaService.hpp>
#include <iostream>

PessoaView::PessoaView()
{
    service = new PessoaService();
    menuLocal = new JustOptionsPanel();
}

void PessoaView::executar()
{
    menuLocal->addOption(new ActionPanel("Criar Pessoa", [this]()
                                         { this->interfaceCriarPessoa(); }));

    menuLocal->addOption(new ActionPanel("Listar Pessoas", [this]()
                                         { this->interfaceListarPessoas(); }));

    menuLocal->addOption(new ActionPanel("Atualizar Pessoa", [this]()
                                         { this->interfaceAtualizarPessoa(); }));

    menuLocal->addOption(new ActionPanel("Excluir Pessoa", [this]()
                                         { this->interfaceExcluirPessoa(); }));

    menuLocal->showPanel();
}

void PessoaView::interfaceCriarPessoa()
{
}

void PessoaView::interfaceListarPessoas()
{
}

void PessoaView::interfaceAtualizarPessoa()
{
}

void PessoaView::interfaceExcluirPessoa()
{
}
