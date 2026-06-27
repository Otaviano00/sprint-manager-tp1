#include "ExcluirPessoaCommand.hpp"
#include <iostream>
#include <string>

ExcluirPessoaCommand::ExcluirPessoaCommand(IPessoaService *service) : PessoaCommand(service) {}

void ExcluirPessoaCommand::executar()
{
    int id = getIdFromUserInput();

    service->excluir(id);

    std::cout << std::endl
              << "Pessoa excluída com sucesso!" << std::endl;
}