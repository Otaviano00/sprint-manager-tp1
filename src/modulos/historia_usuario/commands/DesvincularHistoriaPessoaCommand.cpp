#include <modulos/historia_usuario/commands/DesvincularHistoriaPessoaCommand.hpp>
#include <modulos/historia_usuario/commands/RecuperarHistoriaCommand.hpp>
#include <iostream>

DesvincularHistoriaPessoaCommand::DesvincularHistoriaPessoaCommand(IHistoriaUsuarioService *service) : service(service) {}

void DesvincularHistoriaPessoaCommand::executar()
{
    RecuperarHistoriaCommand recCmd;
    HistoriaDeUsuario historia = recCmd.getHistoriaFromInput();

    service->desvincularPessoa(historia.getId());
    std::cout << "Pessoa desvinculada com sucesso!" << std::endl;
}
