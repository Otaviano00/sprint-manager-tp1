#include <modulos/projeto/ProjetoView.hpp>
#include <modulos/projeto/ProjetoService.hpp>
#include <iostream>

ProjetoView::ProjetoView()
{
    service = new ProjetoService();
    menuLocal = new JustOptionsPanel();
}

void ProjetoView::executar()
{
    menuLocal->addOption(new ActionPanel("Criar Projeto", [this]()
                                         { this->interfaceCriarProjeto(); }));

    menuLocal->addOption(new ActionPanel("Listar Projetos", [this]()
                                         { this->interfaceListarProjetos(); }));

    menuLocal->addOption(new ActionPanel("Listar Projetos por Pessoa", [this]()
                                         { this->interfaceListarProjetosPorPessoa(); }));

    menuLocal->addOption(new ActionPanel("Atualizar Projeto", [this]()
                                         { this->interfaceAtualizarProjeto(); }));

    menuLocal->addOption(new ActionPanel("Excluir Projeto", [this]()
                                         { this->interfaceExcluirProjeto(); }));

    menuLocal->showPanel();
}

void ProjetoView::interfaceCriarProjeto()
{
}

void ProjetoView::interfaceListarProjetos()
{
}

void ProjetoView::interfaceListarProjetosPorPessoa()
{
}

void ProjetoView::interfaceAtualizarProjeto()
{
}

void ProjetoView::interfaceExcluirProjeto()
{
}
