#include "ProjetoCommand.hpp"
#include <iostream>
#include <string>

ProjetoCommand::ProjetoCommand(IProjetoService *service) : service(service) {}

int ProjetoCommand::getIdFromUserInput()
{
    std::string entradaId;
    std::cout << "ID do projeto: ";
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