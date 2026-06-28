#ifndef CRIARHISTORIACOMMAND_HPP
#define CRIARHISTORIACOMMAND_HPP

#include <core/ICommand.hpp>
#include <modulos/historia_usuario/IHistoriaUsuarioService.hpp>

class CriarHistoriaCommand : public ICommand
{
private:
    IHistoriaUsuarioService *service;

public:
    CriarHistoriaCommand(IHistoriaUsuarioService *service);
    void executar() override;
};

#endif
