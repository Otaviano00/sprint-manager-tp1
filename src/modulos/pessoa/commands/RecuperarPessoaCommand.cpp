#include <modulos/pessoa/commands/RecuperarPessoaCommand.hpp>
#include <modulos/pessoa/Pessoa.hpp>
#include <modulos/pessoa/PessoaService.hpp>
#include <dominios/Email.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Senha.hpp>
#include <dominios/Papel.hpp>
#include <iostream>
#include <string>
#include <list>

Pessoa RecuperarPessoaCommand::getPessoaFromInput()
{
    std::string entradaId;
    std::cout << "ID da pessoa: ";
    std::getline(std::cin, entradaId);

    int id;
    try
    {
        id = std::stoi(entradaId);
    }
    catch (const std::invalid_argument &e)
    {
        throw std::invalid_argument("ID inválido. Por favor, insira um número inteiro.");
    }

    try
    {
        IPessoaService *service = new PessoaService();

        Pessoa pessoa = service->listarPorId(id);

        delete service;

        return pessoa;
    }
    catch (const std::exception &e)
    {
        throw std::invalid_argument("Pessoa com ID: " + std::to_string(id) + " não encontrada");
    }
}