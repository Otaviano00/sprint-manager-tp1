#ifndef LISTARHISTORIAPLANOSPRINTCOMMAND_HPP
#define LISTARHISTORIAPLANOSPRINTCOMMAND_HPP

#include <modulos/historia_usuario/IHistoriaUsuarioService.hpp>
#include <core/ICommand.hpp>

class ListarHistoriaPlanoSprintCommand : public ICommand
{
private:
    IHistoriaUsuarioService *service;

public:
    ListarHistoriaPlanoSprintCommand(IHistoriaUsuarioService *service);
    void executar() override;
};

#endif // LISTARHISTORIAPLANOSPRINTCOMMAND_HPP