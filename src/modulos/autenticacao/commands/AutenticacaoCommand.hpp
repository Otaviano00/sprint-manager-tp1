#ifndef AUTENTICACAOCOMMAND_HPP
#define AUTENTICACAOCOMMAND_HPP

#include <core/ICommand.hpp>
#include <modulos/autenticacao/IAutenticacaoService.hpp>
#include <modulos/pessoa/IPessoaService.hpp>

class AutenticacaoCommand : public ICommand
{
protected:
    IAutenticacaoService *service;
    IPessoaService *pessoaService;

public:
    AutenticacaoCommand(IAutenticacaoService *service, IPessoaService *pessoaService = nullptr);
    virtual ~AutenticacaoCommand() = default;
};

#endif // AUTENTICACAOCOMMAND_HPP