#ifndef ALTERARESTADOHISTORIACOMMAND_HPP
#define ALTERARESTADOHISTORIACOMMAND_HPP

#include <core/ICommand.hpp>
#include <modulos/historia_usuario/IHistoriaUsuarioService.hpp>

class AlterarEstadoHistoriaCommand : public ICommand
{
private:
    IHistoriaUsuarioService *service;

public:
    AlterarEstadoHistoriaCommand(IHistoriaUsuarioService *service);
    void executar() override;
};

#endif
