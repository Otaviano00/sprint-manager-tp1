#ifndef EXCLUIRPROJETOCOMMAND_HPP
#define EXCLUIRPROJETOCOMMAND_HPP

#include "ProjetoCommand.hpp"

class ExcluirProjetoCommand : public ProjetoCommand
{
public:
    ExcluirProjetoCommand(IProjetoService *service);
    void executar() override;
};

#endif // EXCLUIRPROJETOCOMMAND_HPP