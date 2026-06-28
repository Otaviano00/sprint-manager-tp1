#ifndef MOVERHISTORIASPRINTCOMMAND_HPP
#define MOVERHISTORIASPRINTCOMMAND_HPP

#include <core/ICommand.hpp>
#include <modulos/historia_usuario/IHistoriaUsuarioService.hpp>

class MoverHistoriaSprintCommand : public ICommand
{
private:
    IHistoriaUsuarioService *service;

public:
    MoverHistoriaSprintCommand(IHistoriaUsuarioService *service);
    void executar() override;
};

#endif
