#ifndef DESVINCULARHISTORIAPESSOACOMMAND_HPP
#define DESVINCULARHISTORIAPESSOACOMMAND_HPP

#include <core/ICommand.hpp>
#include <modulos/historia_usuario/IHistoriaUsuarioService.hpp>

class DesvincularHistoriaPessoaCommand : public ICommand
{
private:
    IHistoriaUsuarioService *service;

public:
    DesvincularHistoriaPessoaCommand(IHistoriaUsuarioService *service);
    void executar() override;
};

#endif
