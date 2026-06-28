#ifndef CRIARPLANOSPRINTCOMMAND_HPP
#define CRIARPLANOSPRINTCOMMAND_HPP

#include <modulos/plano_sprint/commands/PlanoSprintCommand.hpp>

class CriarPlanoSprintCommand : public PlanoSprintCommand
{
public:
    CriarPlanoSprintCommand(IPlanoSprintService *service);
    void executar() override;
};

#endif // CRIARPLANOSPRINTCOMMAND_HPP