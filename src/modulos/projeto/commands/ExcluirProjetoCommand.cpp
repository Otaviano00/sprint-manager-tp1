#include <modulos/projeto/commands/ExcluirProjetoCommand.hpp>
#include <modulos/projeto/commands/RecuperarProjetoCommand.hpp>
#include <iostream>

ExcluirProjetoCommand::ExcluirProjetoCommand(IProjetoService *service) : ProjetoCommand(service) {}

void ExcluirProjetoCommand::executar()
{
    Projeto projeto = RecuperarProjetoCommand().getProjetoFromInput();

    service->excluir(projeto.getId());

    std::cout << std::endl
              << "Projeto excluído com sucesso!" << std::endl;
}