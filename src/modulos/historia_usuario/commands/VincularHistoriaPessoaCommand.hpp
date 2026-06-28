#ifndef VINCULARHISTORIAPESSOACOMMAND_HPP
#define VINCULARHISTORIAPESSOACOMMAND_HPP

#include <core/ICommand.hpp>
#include <modulos/historia_usuario/IHistoriaUsuarioService.hpp>

class VincularHistoriaPessoaCommand : public ICommand
{
private:
    IHistoriaUsuarioService *service;

public:
    VincularHistoriaPessoaCommand(IHistoriaUsuarioService *service);
    void executar() override;
};

#endif
