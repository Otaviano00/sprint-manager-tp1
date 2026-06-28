#ifndef PRIMEIROACESSOCOMMAND_HPP
#define PRIMEIROACESSOCOMMAND_HPP

#include "AutenticacaoCommand.hpp"

class PrimeiroAcessoCommand : public AutenticacaoCommand
{
public:
    PrimeiroAcessoCommand(IAutenticacaoService *service, IPessoaService *pessoaService);
    void executar() override;
};

#endif // PRIMEIROACESSOCOMMAND_HPP