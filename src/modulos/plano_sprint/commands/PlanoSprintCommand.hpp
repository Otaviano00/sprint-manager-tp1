#ifndef PLANOSPRINTCOMMAND_HPP
#define PLANOSPRINTCOMMAND_HPP

#include <core/ICommand.hpp>
#include <modulos/plano_sprint/IPlanoSprintService.hpp>

class PlanoSprintCommand : public ICommand
{
protected:
    IPlanoSprintService *service;

public:
    PlanoSprintCommand(IPlanoSprintService *service);
    virtual ~PlanoSprintCommand() = default;
};

#endif // PLANOSPRINTCOMMAND_HPP