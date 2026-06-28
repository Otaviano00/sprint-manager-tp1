#include <modulos/projeto/Projeto.hpp>
#include <modulos/projeto/commands/BuscarProjetoCommand.hpp>
#include <modulos/projeto/commands/RecuperarProjetoCommand.hpp>
#include <iostream>

BuscarProjetoCommand::BuscarProjetoCommand(IProjetoService *service) : ProjetoCommand(service) {}

void BuscarProjetoCommand::executar()
{
    Projeto projeto = RecuperarProjetoCommand().getProjetoFromInput();

    std::cout << "Projeto encontrado:" << std::endl;
    std::cout << "- ID: " << projeto.getId()
              << " | Codigo: " << projeto.getCodigo().getValor()
              << " | Nome: " << projeto.getNome().getValor()
              << " | Pessoa: " << projeto.getPessoa().getId() << std::endl;
}