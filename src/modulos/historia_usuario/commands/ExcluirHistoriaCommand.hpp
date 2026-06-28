#ifndef EXCLUIRHISTORIACOMMAND_HPP
#define EXCLUIRHISTORIACOMMAND_HPP

#include <core/ICommand.hpp>
#include <modulos/historia_usuario/IHistoriaUsuarioService.hpp>

class ExcluirHistoriaCommand : public ICommand
{
private:
    IHistoriaUsuarioService *service;

public:
    ExcluirHistoriaCommand(IHistoriaUsuarioService *service);
    void executar() override;
};

#endif
