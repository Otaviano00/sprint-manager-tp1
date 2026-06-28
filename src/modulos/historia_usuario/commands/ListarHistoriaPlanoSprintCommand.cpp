#include <modulos/plano_sprint/PlanoSprint.hpp>
#include <modulos/plano_sprint/commands/RecuperarPlanoSprintCommand.hpp>
#include <modulos/historia_usuario/commands/ListarHistoriaPlanoSprintCommand.hpp>
#include <iostream>
#include <list>

ListarHistoriaPlanoSprintCommand::ListarHistoriaPlanoSprintCommand(IHistoriaUsuarioService *service) {}

void ListarHistoriaPlanoSprintCommand::executar()
{
    PlanoSprint planoSprint = RecuperarPlanoSprintCommand().getPlanoSprintFromInput();

    std::list<HistoriaDeUsuario> list = service->listarPorPlanoSprint(planoSprint);

    if (list.empty())
    {
        std::cout << "Nenhuma historia cadastrada." << std::endl;
        return;
    }

    std::cout << "--- Historias de Usuario ---" << std::endl;
    for (const auto &h : list)
    {
        std::cout << "ID: " << h.getId()
                  << " | Codigo: " << h.getCodigo().getValor()
                  << " | Status: " << h.getEstado().getValor() << std::endl;
    }
}