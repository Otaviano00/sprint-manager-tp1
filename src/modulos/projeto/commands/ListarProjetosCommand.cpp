#include "ListarProjetosCommand.hpp"
#include <modulos/projeto/Projeto.hpp>
#include <iostream>
#include <list>

ListarProjetosCommand::ListarProjetosCommand(IProjetoService *service) : ProjetoCommand(service) {}

void ListarProjetosCommand::executar()
{
    std::list<Projeto> projetos = service->listar();

    if (projetos.empty())
    {
        std::cout << "Nenhum projeto cadastrado." << std::endl;
        return;
    }

    std::cout << "Projetos cadastrados:" << std::endl;
    for (const auto &projeto : projetos)
    {
        std::cout << "- ID: " << projeto.getId()
                  << " | Codigo: " << projeto.getCodigo().getValor()
                  << " | Nome: " << projeto.getNome().getValor()
                  << " | Pessoa: " << projeto.getPessoa().getId() << std::endl;
    }
}