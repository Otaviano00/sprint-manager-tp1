#ifndef ATUALIZARPLANOSPRINTCOMMAND_HPP
#define ATUALIZARPLANOSPRINTCOMMAND_HPP

#include <modulos/plano_sprint/commands/PlanoSprintCommand.hpp>

class AtualizarPlanoSprintCommand : public PlanoSprintCommand
{
public:
    AtualizarPlanoSprintCommand(IPlanoSprintService *service);
    void executar() override;
};

#endif // ATUALIZARPLANOSPRINTCOMMAND_HPP