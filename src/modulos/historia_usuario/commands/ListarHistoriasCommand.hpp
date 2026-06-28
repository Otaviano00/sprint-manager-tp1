#ifndef LISTARHISTORIASCOMMAND_HPP
#define LISTARHISTORIASCOMMAND_HPP

#include <core/ICommand.hpp>
#include <modulos/historia_usuario/IHistoriaUsuarioService.hpp>

class ListarHistoriasCommand : public ICommand
{
private:
    IHistoriaUsuarioService *service;

public:
    ListarHistoriasCommand(IHistoriaUsuarioService *service);
    void executar() override;
};

#endif
