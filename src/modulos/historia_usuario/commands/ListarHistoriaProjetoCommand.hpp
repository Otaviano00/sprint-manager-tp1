#ifndef LISTARHISTORIAPROJETOCOMMAND_HPP
#define LISTARHISTORIAPROJETOCOMMAND_HPP

#include <modulos/historia_usuario/IHistoriaUsuarioService.hpp>
#include <core/ICommand.hpp>

class ListarHistoriaProjetoCommand : public ICommand
{
private:
    IHistoriaUsuarioService *service;

public:
    ListarHistoriaProjetoCommand(IHistoriaUsuarioService *service);
    void executar() override;
};

#endif // LISTARHISTORIAPROJETOCOMMAND_HPP