#include <modulos/historia_usuario/commands/VincularHistoriaPessoaCommand.hpp>
#include <modulos/historia_usuario/commands/RecuperarHistoriaCommand.hpp>
#include <modulos/pessoa/commands/RecuperarPessoaCommand.hpp>
#include <iostream>

VincularHistoriaPessoaCommand::VincularHistoriaPessoaCommand(IHistoriaUsuarioService *service) : service(service) {}

void VincularHistoriaPessoaCommand::executar()
{
    RecuperarHistoriaCommand recCmd;
    HistoriaDeUsuario historia = recCmd.getHistoriaFromInput();

    RecuperarPessoaCommand recPesCmd;
    Pessoa pessoa = recPesCmd.getPessoaFromInput();

    service->vincularPessoa(historia.getId(), pessoa);
    std::cout << "Pessoa vinculada com sucesso!" << std::endl;
}
