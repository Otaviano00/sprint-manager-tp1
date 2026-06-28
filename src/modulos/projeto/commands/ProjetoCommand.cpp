#include <modulos/projeto/commands/ProjetoCommand.hpp>
#include <iostream>
#include <string>

ProjetoCommand::ProjetoCommand(IProjetoService *service) : service(service) {}
