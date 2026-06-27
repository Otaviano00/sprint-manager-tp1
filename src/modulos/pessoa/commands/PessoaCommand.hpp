#ifndef PESSOACOMMAND_HPP
#define PESSOACOMMAND_HPP

#include <core/ICommand.hpp>
#include <modulos/pessoa/IPessoaService.hpp>

class PessoaCommand : public ICommand
{
protected:
    IPessoaService *service;

    int getIdFromUserInput();

public:
    PessoaCommand(IPessoaService *service);
    virtual ~PessoaCommand() = default;
};

#endif // PESSOACOMMAND_HPP