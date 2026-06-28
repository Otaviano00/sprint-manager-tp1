#ifndef EXCLUIRPROJETOCOMMAND_HPP
#define EXCLUIRPROJETOCOMMAND_HPP

#include <modulos/projeto/commands/ProjetoCommand.hpp>

class ExcluirProjetoCommand : public ProjetoCommand
{
public:
    ExcluirProjetoCommand(IProjetoService *service);
    void executar() override;
};

#endif // EXCLUIRPROJETOCOMMAND_HPP