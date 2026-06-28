#include <modulos/plano_sprint/commands/ExcluirPlanoSprintCommand.hpp>
#include <modulos/plano_sprint/commands/RecuperarPlanoSprintCommand.hpp>
#include <iostream>
#include <string>

ExcluirPlanoSprintCommand::ExcluirPlanoSprintCommand(IPlanoSprintService *service) : PlanoSprintCommand(service) {}

void ExcluirPlanoSprintCommand::executar()
{
    PlanoSprint planoSprint = RecuperarPlanoSprintCommand().getPlanoSprintFromInput();

    service->excluir(planoSprint.getId());

    std::cout << std::endl
              << "Plano de Sprint excluída com sucesso!" << std::endl;
}