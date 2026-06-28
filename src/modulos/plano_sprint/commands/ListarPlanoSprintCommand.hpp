#ifndef LISTARPLANOSPRINTSCOMMAND_HPP
#define LISTARPLANOSPRINTSCOMMAND_HPP

#include <modulos/plano_sprint/commands/PlanoSprintCommand.hpp>

class ListarPlanoSprintCommand : public PlanoSprintCommand
{
public:
    ListarPlanoSprintCommand(IPlanoSprintService *service);
    void executar() override;
};

#endif // LISTARPLANOSPRINTSCOMMAND_HPP