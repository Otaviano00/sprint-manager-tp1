#include <modulos/pessoa/commands/ExcluirPessoaCommand.hpp>
#include <modulos/pessoa/commands/RecuperarPessoaCommand.hpp>
#include <iostream>
#include <string>

ExcluirPessoaCommand::ExcluirPessoaCommand(IPessoaService *service) : PessoaCommand(service) {}

void ExcluirPessoaCommand::executar()
{
    Pessoa pessoa = RecuperarPessoaCommand().getPessoaFromInput();

    service->excluir(pessoa.getId());

    std::cout << std::endl
              << "Pessoa excluída com sucesso!" << std::endl;
}