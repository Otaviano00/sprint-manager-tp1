#include "ExcluirProjetoCommand.hpp"
#include <iostream>

ExcluirProjetoCommand::ExcluirProjetoCommand(IProjetoService *service) : ProjetoCommand(service) {}

void ExcluirProjetoCommand::executar()
{
    int id = getIdFromUserInput();

    service->excluir(id);

    std::cout << std::endl
              << "Projeto excluído com sucesso!" << std::endl;
}