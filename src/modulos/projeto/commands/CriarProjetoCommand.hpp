#ifndef CRIARPROJETOCOMMAND_HPP
#define CRIARPROJETOCOMMAND_HPP

#include "ProjetoCommand.hpp"

class CriarProjetoCommand : public ProjetoCommand
{
public:
    CriarProjetoCommand(IProjetoService *service);
    void executar() override;
};

#endif // CRIARPROJETOCOMMAND_HPP