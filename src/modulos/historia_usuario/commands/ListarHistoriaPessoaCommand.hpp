#ifndef LISTARHISTORIAPESSOACOMMAND_HPP
#define LISTARHISTORIAPESSOACOMMAND_HPP

#include <modulos/historia_usuario/IHistoriaUsuarioService.hpp>
#include <core/ICommand.hpp>

class ListarHistoriaPessoaCommand : public ICommand
{
private:
    IHistoriaUsuarioService *service;

public:
    ListarHistoriaPessoaCommand(IHistoriaUsuarioService *service);
    void executar() override;
};

#endif // LISTARHISTORIAPESSOACOMMAND_HPP