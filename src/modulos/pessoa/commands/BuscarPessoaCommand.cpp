#include "BuscarPessoaCommand.hpp"
#include <modulos/pessoa/Pessoa.hpp>
#include <dominios/Email.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Senha.hpp>
#include <dominios/Papel.hpp>
#include <iostream>
#include <string>

BuscarPessoaCommand::BuscarPessoaCommand(IPessoaService *service) : PessoaCommand(service) {}

void BuscarPessoaCommand::executar()
{
    int id = getIdFromUserInput();

    Pessoa pessoa = service->listarPorId(id);

    std::cout << std::endl
              << "Pessoa encontrada:" << std::endl;
    std::cout << "- ID: " << pessoa.getId()
              << " | Nome: " << pessoa.getNome().getValor()
              << " | Email: " << pessoa.getEmail().getValor()
              << " | Papel: " << pessoa.getPapel().getValor() << std::endl;
}