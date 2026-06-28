#ifndef LISTARPLANOSPRINTSPROJETOCOMMAND_HPP
#define LISTARPLANOSPRINTSPROJETOCOMMAND_HPP

#include <modulos/plano_sprint/commands/PlanoSprintCommand.hpp>

class ListarPlanoSprintProjetoCommand : public PlanoSprintCommand
{
public:
    ListarPlanoSprintProjetoCommand(IPlanoSprintService *service);
    void executar() override;
};

#endif // LISTARPLANOSPRINTSPROJETOCOMMAND_HPP