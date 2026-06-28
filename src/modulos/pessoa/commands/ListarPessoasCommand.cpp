#include <modulos/pessoa/commands/ListarPessoasCommand.hpp>
#include <modulos/pessoa/Pessoa.hpp>
#include <dominios/Email.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Senha.hpp>
#include <dominios/Papel.hpp>
#include <iostream>
#include <list>

ListarPessoasCommand::ListarPessoasCommand(IPessoaService *service) : PessoaCommand(service) {}

void ListarPessoasCommand::executar()
{
    std::list<Pessoa> pessoas = service->listar();

    if (pessoas.empty())
    {
        std::cout << "Nenhuma pessoa cadastrada." << std::endl;
        return;
    }

    std::cout << "Pessoas cadastradas:" << std::endl;
    for (const auto &pessoa : pessoas)
    {
        std::cout << "- ID: " << pessoa.getId()
                  << " | Nome: " << pessoa.getNome().getValor()
                  << " | Email: " << pessoa.getEmail().getValor()
                  << " | Papel: " << pessoa.getPapel().getValor() << std::endl;
    }
}