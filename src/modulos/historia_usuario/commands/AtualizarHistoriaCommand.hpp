#ifndef ATUALIZARHISTORIACOMMAND_HPP
#define ATUALIZARHISTORIACOMMAND_HPP

#include <core/ICommand.hpp>
#include <modulos/historia_usuario/IHistoriaUsuarioService.hpp>

class AtualizarHistoriaCommand : public ICommand {
private:
    IHistoriaUsuarioService* service;
public:
    AtualizarHistoriaCommand(IHistoriaUsuarioService* service);
    void executar() override;
};

#endif
