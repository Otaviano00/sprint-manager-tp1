#include <modulos/historia_usuario/commands/MoverHistoriaSprintCommand.hpp>
#include <modulos/historia_usuario/commands/RecuperarHistoriaCommand.hpp>
#include <modulos/plano_sprint/PlanoSprintService.hpp>
#include <iostream>

MoverHistoriaSprintCommand::MoverHistoriaSprintCommand(IHistoriaUsuarioService *service) : service(service) {}

void MoverHistoriaSprintCommand::executar()
{
    RecuperarHistoriaCommand recCmd;
    HistoriaDeUsuario historia = recCmd.getHistoriaFromInput();

    std::string spId_str;
    std::cout << "ID da Plano de Sprint destino: ";
    std::getline(std::cin, spId_str);
    int spId = std::stoi(spId_str);

    // Simulando a validacao de sprint igual foi feito.
    // No proprio service ele busca pra ver se excede capacidade, e checa id no repositório.
    PlanoSprint fakeRef(spId);

    service->moverParaSprint(historia.getId(), fakeRef);
    std::cout << "Historia movida com sucesso!" << std::endl;
}
