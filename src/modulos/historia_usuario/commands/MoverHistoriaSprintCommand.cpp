#include <modulos/historia_usuario/commands/MoverHistoriaSprintCommand.hpp>
#include <modulos/historia_usuario/commands/RecuperarHistoriaCommand.hpp>
#include <modulos/plano_sprint/commands/RecuperarPlanoSprintCommand.hpp>
#include <modulos/plano_sprint/PlanoSprintService.hpp>
#include <iostream>

MoverHistoriaSprintCommand::MoverHistoriaSprintCommand(IHistoriaUsuarioService *service) : service(service)
{
}

void MoverHistoriaSprintCommand::executar()
{
    RecuperarHistoriaCommand recCmd;
    HistoriaDeUsuario historia = recCmd.getHistoriaFromInput();

    PlanoSprint planoSprint = RecuperarPlanoSprintCommand().getPlanoSprintFromInput();

    service->moverParaSprint(historia.getId(), planoSprint);
    std::cout << "Historia movida com sucesso!" << std::endl;
}
