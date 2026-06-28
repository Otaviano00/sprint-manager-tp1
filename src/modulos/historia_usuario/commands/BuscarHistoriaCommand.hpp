#ifndef BUSCARHISTORIACOMMAND_HPP
#define BUSCARHISTORIACOMMAND_HPP

#include <core/ICommand.hpp>
#include <modulos/historia_usuario/IHistoriaUsuarioService.hpp>

class BuscarHistoriaCommand : public ICommand
{
private:
    IHistoriaUsuarioService *service;

public:
    BuscarHistoriaCommand(IHistoriaUsuarioService *service);
    void executar() override;
};

#endif
