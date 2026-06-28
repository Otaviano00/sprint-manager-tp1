#ifndef PROJETOCOMMAND_HPP
#define PROJETOCOMMAND_HPP

#include <core/ICommand.hpp>
#include <modulos/projeto/IProjetoService.hpp>

class ProjetoCommand : public ICommand
{
protected:
    IProjetoService *service;

public:
    ProjetoCommand(IProjetoService *service);
    virtual ~ProjetoCommand() = default;
};

#endif // PROJETOCOMMAND_HPP