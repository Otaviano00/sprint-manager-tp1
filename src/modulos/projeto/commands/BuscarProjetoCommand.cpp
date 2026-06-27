#include "BuscarProjetoCommand.hpp"
#include <modulos/projeto/Projeto.hpp>
#include <iostream>

BuscarProjetoCommand::BuscarProjetoCommand(IProjetoService *service) : ProjetoCommand(service) {}

void BuscarProjetoCommand::executar()
{
    int id = getIdFromUserInput();

    Projeto projeto = service->listarPorId(id);

    std::cout << "Projeto encontrado:" << std::endl;
    std::cout << "- ID: " << projeto.getId()
              << " | Codigo: " << projeto.getCodigo().getValor()
              << " | Nome: " << projeto.getNome().getValor()
              << " | Pessoa: " << projeto.getPessoa().getId() << std::endl;
}