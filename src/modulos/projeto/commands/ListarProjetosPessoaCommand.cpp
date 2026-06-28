#include <modulos/projeto/Projeto.hpp>
#include <modulos/projeto/commands/ListarProjetosPessoaCommand.hpp>
#include <modulos/pessoa/commands/RecuperarPessoaCommand.hpp>
#include <iostream>
#include <list>

ListarProjetosPessoaCommand::ListarProjetosPessoaCommand(IProjetoService *service) : ProjetoCommand(service) {}

void ListarProjetosPessoaCommand::executar()
{
    Pessoa pessoa = RecuperarPessoaCommand().getPessoaFromInput();

    std::list<Projeto> projetos = service->listarPorPessoa(pessoa);

    if (projetos.empty())
    {
        std::cout << "Nenhum projeto associado a esta pessoa." << std::endl;
        return;
    }

    std::cout << "Projetos associados:" << std::endl;
    for (const auto &projeto : projetos)
    {
        std::cout << "- ID: " << projeto.getId()
                  << " | Codigo: " << projeto.getCodigo().getValor()
                  << " | Nome: " << projeto.getNome().getValor()
                  << " | Pessoa: " << projeto.getPessoa().getId() << std::endl;
    }
}