#include <modulos/historia_usuario/commands/ListarHistoriasCommand.hpp>
#include <iostream>

ListarHistoriasCommand::ListarHistoriasCommand(IHistoriaUsuarioService *service) : service(service) {}

void ListarHistoriasCommand::executar()
{
    auto list = service->listar();
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
