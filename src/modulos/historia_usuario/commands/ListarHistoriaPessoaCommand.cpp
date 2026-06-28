#include <modulos/pessoa/Pessoa.hpp>
#include <modulos/pessoa/commands/RecuperarPessoaCommand.hpp>
#include <modulos/historia_usuario/commands/ListarHistoriaPessoaCommand.hpp>
#include <iostream>
#include <list>

ListarHistoriaPessoaCommand::ListarHistoriaPessoaCommand(IHistoriaUsuarioService *service) {}

void ListarHistoriaPessoaCommand::executar()
{
    Pessoa Pessoa = RecuperarPessoaCommand().getPessoaFromInput();

    std::list<HistoriaDeUsuario> list = service->listarPorPessoa(Pessoa);

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