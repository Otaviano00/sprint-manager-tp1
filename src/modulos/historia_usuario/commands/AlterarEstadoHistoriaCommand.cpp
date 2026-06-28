#include <modulos/historia_usuario/commands/AlterarEstadoHistoriaCommand.hpp>
#include <modulos/historia_usuario/commands/RecuperarHistoriaCommand.hpp>
#include <iostream>

AlterarEstadoHistoriaCommand::AlterarEstadoHistoriaCommand(IHistoriaUsuarioService *service) : service(service) {}

void AlterarEstadoHistoriaCommand::executar()
{
    RecuperarHistoriaCommand recCmd;
    HistoriaDeUsuario historia = recCmd.getHistoriaFromInput();

    std::string novo;
    std::cout << "Novo Estado (A FAZER, FAZENDO, FEITO): ";
    std::getline(std::cin, novo);

    std::cout << std::endl
              << "Alterando estado da historia de usuario..." << novo << std::endl;

    service->alterarEstado(historia.getId(), novo);
    std::cout << std::endl
              << "Estado alterado com sucesso!";
}
