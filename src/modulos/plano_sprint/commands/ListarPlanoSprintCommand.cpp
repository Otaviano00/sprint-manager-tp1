#include <modulos/plano_sprint/commands/ListarPlanoSprintCommand.hpp>
#include <modulos/plano_sprint/PlanoSprint.hpp>
#include <dominios/Email.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Senha.hpp>
#include <dominios/Papel.hpp>
#include <iostream>
#include <list>

ListarPlanoSprintCommand::ListarPlanoSprintCommand(IPlanoSprintService *service) : PlanoSprintCommand(service)
{
}

void ListarPlanoSprintCommand::executar()
{
    std::list<PlanoSprint> planosSprint = service->listar();

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