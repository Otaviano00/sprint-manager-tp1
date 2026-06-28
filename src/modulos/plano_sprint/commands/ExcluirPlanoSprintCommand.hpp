#ifndef EXCLUIRPLANOSPRINTSCOMMAND_HPP
#define EXCLUIRPLANOSPRINTSCOMMAND_HPP

#include <modulos/plano_sprint/commands/PlanoSprintCommand.hpp>

class ExcluirPlanoSprintCommand : public PlanoSprintCommand
{
public:
    ExcluirPlanoSprintCommand(IPlanoSprintService *service);
    void executar() override;
};

#endif // EXCLUIRPLANOSPRINTSCOMMAND_HPP