#include "LogoutCommand.hpp"
#include <iostream>

LogoutCommand::LogoutCommand(IAutenticacaoService *service) : AutenticacaoCommand(service) {}

void LogoutCommand::executar()
{
    service->logout();
    std::cout << std::endl
              << "Logout realizado com sucesso!" << std::endl;
}