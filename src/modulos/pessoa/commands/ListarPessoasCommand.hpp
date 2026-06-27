#ifndef LISTARPESSOASCOMMAND_HPP
#define LISTARPESSOASCOMMAND_HPP

#include "PessoaCommand.hpp"

class ListarPessoasCommand : public PessoaCommand
{
public:
    ListarPessoasCommand(IPessoaService *service);
    void executar() override;
};

#endif // LISTARPESSOASCOMMAND_HPP