#ifndef ATUALIZARPROJETOCOMMAND_HPP
#define ATUALIZARPROJETOCOMMAND_HPP

#include "ProjetoCommand.hpp"

class AtualizarProjetoCommand : public ProjetoCommand
{
public:
    AtualizarProjetoCommand(IProjetoService *service);
    void executar() override;
};

#endif // ATUALIZARPROJETOCOMMAND_HPP