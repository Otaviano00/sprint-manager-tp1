#include <modulos/projeto/Projeto.hpp>
#include <modulos/projeto/commands/RecuperarProjetoCommand.hpp>
#include <modulos/historia_usuario/commands/ListarHistoriaProjetoCommand.hpp>
#include <iostream>
#include <list>

ListarHistoriaProjetoCommand::ListarHistoriaProjetoCommand(IHistoriaUsuarioService *service) {}

void ListarHistoriaProjetoCommand::executar()
{
    Projeto projeto = RecuperarProjetoCommand().getProjetoFromInput();

    std::list<HistoriaDeUsuario> list = service->listarPorProjeto(projeto);

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