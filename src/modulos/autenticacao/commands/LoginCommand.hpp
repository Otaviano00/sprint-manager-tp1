#ifndef LOGINCOMMAND_HPP
#define LOGINCOMMAND_HPP

#include "AutenticacaoCommand.hpp"

class LoginCommand : public AutenticacaoCommand
{
public:
    LoginCommand(IAutenticacaoService *service);
    void executar() override;
};

#endif // LOGINCOMMAND_HPP