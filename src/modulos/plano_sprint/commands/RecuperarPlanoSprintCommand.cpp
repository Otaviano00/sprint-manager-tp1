#include <modulos/plano_sprint/commands/RecuperarPlanoSprintCommand.hpp>
#include <modulos/plano_sprint/PlanoSprint.hpp>
#include <modulos/plano_sprint/PlanoSprintService.hpp>
#include <dominios/Email.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Senha.hpp>
#include <dominios/Papel.hpp>
#include <iostream>
#include <string>
#include <list>

PlanoSprint RecuperarPlanoSprintCommand::getPlanoSprintFromInput()
{
    std::string entradaId;
    std::cout << "ID do plano de sprint: ";
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
        IPlanoSprintService *service = new PlanoSprintService();

        PlanoSprint planoSprint = service->listarPorId(id);

        delete service;

        return planoSprint;
    }
    catch (const std::exception &e)
    {
        throw std::invalid_argument("Plano de Sprint com ID: " + std::to_string(id) + " não encontrado");
    }
}