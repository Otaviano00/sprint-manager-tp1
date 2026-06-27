#ifndef BUSCARPROJETOCOMMAND_HPP
#define BUSCARPROJETOCOMMAND_HPP

#include "ProjetoCommand.hpp"

class BuscarProjetoCommand : public ProjetoCommand
{
public:
    BuscarProjetoCommand(IProjetoService *service);
    void executar() override;
};

#endif // BUSCARPROJETOCOMMAND_HPP