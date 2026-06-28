#include <modulos/historia_usuario/commands/ExcluirHistoriaCommand.hpp>
#include <modulos/historia_usuario/commands/RecuperarHistoriaCommand.hpp>
#include <iostream>

ExcluirHistoriaCommand::ExcluirHistoriaCommand(IHistoriaUsuarioService *service) : service(service) {}

void ExcluirHistoriaCommand::executar()
{
    RecuperarHistoriaCommand recCmd;
    HistoriaDeUsuario historia = recCmd.getHistoriaFromInput();

    service->excluir(historia.getId());
    std::cout << "Historia excluida com sucesso!" << std::endl;
}
