#ifndef LISTARPESSOASCOMMAND_HPP
#define LISTARPESSOASCOMMAND_HPP

#include <modulos/pessoa/commands/PessoaCommand.hpp>

class ListarPessoasCommand : public PessoaCommand
{
public:
    ListarPessoasCommand(IPessoaService *service);
    void executar() override;
};

#endif // LISTARPESSOASCOMMAND_HPP