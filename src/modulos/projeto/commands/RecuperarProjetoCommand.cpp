#include <modulos/projeto/commands/RecuperarProjetoCommand.hpp>
#include <modulos/projeto/Projeto.hpp>
#include <modulos/projeto/ProjetoService.hpp>
#include <dominios/Email.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Senha.hpp>
#include <dominios/Papel.hpp>
#include <iostream>
#include <string>
#include <list>

Projeto RecuperarProjetoCommand::getProjetoFromInput()
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

    try
    {
        IProjetoService *service = new ProjetoService();

        Projeto projeto = service->listarPorId(id);

        delete service;

        return projeto;
    }
    catch (const std::exception &e)
    {
        throw std::invalid_argument("Projeto com ID: " + std::to_string(id) + " não encontrado");
    }
}