#include <modulos/projeto/Projeto.hpp>
#include <modulos/projeto/commands/RecuperarProjetoCommand.hpp>
#include <modulos/plano_sprint/commands/ListarPlanoSprintProjetoCommand.hpp>
#include <iostream>
#include <list>

ListarPlanoSprintProjetoCommand::ListarPlanoSprintProjetoCommand(IPlanoSprintService *service) : PlanoSprintCommand(service) {}

void ListarPlanoSprintProjetoCommand::executar()
{
    Projeto projeto = RecuperarProjetoCommand().getProjetoFromInput();

    std::list<PlanoSprint> planosSprint = service->listarPorProjeto(projeto);

    if (planosSprint.empty())
    {
        std::cout << "Nenhum plano de sprint cadastrado." << std::endl;
        return;
    }
    std::cout << "Planos de sprint cadastrados:" << std::endl;
    for (const auto &planoSprint : planosSprint)
    {
        std::cout << "- ID: " << planoSprint.getId()
                  << " | Codig: " << planoSprint.getCodigo().getValor()
                  << " | Nome: " << planoSprint.getNome().getValor()
                  << " | Data Inicio: " << planoSprint.getDataInicio().getValor()
                  << " | Data Fim: " << planoSprint.getDataFim().getValor()
                  << " | Projeto: " << planoSprint.getProjeto().getId() << std::endl;
    }
}