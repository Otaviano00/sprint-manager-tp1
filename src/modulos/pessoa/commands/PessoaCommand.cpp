#include "PessoaCommand.hpp"
#include <iostream>
#include <string>

PessoaCommand::PessoaCommand(IPessoaService *service) : service(service) {}

int PessoaCommand::getIdFromUserInput()
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

    return id;
}