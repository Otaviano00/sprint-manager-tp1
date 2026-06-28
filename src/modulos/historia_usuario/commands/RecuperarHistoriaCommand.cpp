#include <modulos/historia_usuario/commands/RecuperarHistoriaCommand.hpp>
#include <modulos/historia_usuario/HistoriaUsuarioService.hpp>
#include <iostream>
#include <string>

HistoriaDeUsuario RecuperarHistoriaCommand::getHistoriaFromInput()
{
    std::string entradaId;
    std::cout << "ID da Historia de Usuario: ";
    std::getline(std::cin, entradaId);

    int id;
    try
    {
        id = std::stoi(entradaId);
    }
    catch (const std::invalid_argument &e)
    {
        throw std::invalid_argument("ID invalido. Por favor, insira um numero inteiro.");
    }

    try
    {
        IHistoriaUsuarioService *service = new HistoriaUsuarioService();
        HistoriaDeUsuario historia = service->listarPorId(id);
        delete service;
        return historia;
    }
    catch (const std::exception &e)
    {
        throw std::invalid_argument("Historia de Usuario com ID " + std::to_string(id) + " nao encontrada.");
    }
}
