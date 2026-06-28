#include <modulos/historia_usuario/commands/BuscarHistoriaCommand.hpp>
#include <modulos/historia_usuario/commands/RecuperarHistoriaCommand.hpp>
#include <iostream>

BuscarHistoriaCommand::BuscarHistoriaCommand(IHistoriaUsuarioService *service) : service(service) {}

void BuscarHistoriaCommand::executar()
{
    RecuperarHistoriaCommand recCmd;
    HistoriaDeUsuario historia = recCmd.getHistoriaFromInput();

    std::cout << std::endl
              << "--- Detalhes da Historia ---"
              << std::endl;

    std::cout << "ID: " << historia.getId() << std::endl;
    std::cout << "Codigo: " << historia.getCodigo().getValor() << std::endl;
    std::cout << "Titulo: " << historia.getTitulo().getValor() << std::endl;
    std::cout << "Como um: " << historia.getPapel().getValor() << std::endl;
    std::cout << "Eu quero: " << historia.getAcao().getValor() << std::endl;
    std::cout << "Para: " << historia.getValor().getValor() << std::endl;
    std::cout << "Estimativa: " << historia.getEstimativa().getValor() << " dias" << std::endl;
    std::cout << "Prioridade: " << historia.getPrioridade().getValor() << std::endl;
    std::cout << "Status: " << historia.getEstado().getValor() << std::endl;
    std::cout << "Projeto ID: " << historia.getProjeto().getId() << std::endl;
    std::cout << "Sprint ID: " << historia.getPlanoSprint().getId() << std::endl;
    std::cout << "Dev Assinalado ID: " << historia.getPessoa().getId() << std::endl;
}
