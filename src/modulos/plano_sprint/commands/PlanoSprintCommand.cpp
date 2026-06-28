#include <modulos/plano_sprint/commands/PlanoSprintCommand.hpp>
#include <iostream>
#include <string>

PlanoSprintCommand::PlanoSprintCommand(IPlanoSprintService *service) : service(service) {}
