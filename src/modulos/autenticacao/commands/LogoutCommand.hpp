#ifndef LOGOUTCOMMAND_HPP
#define LOGOUTCOMMAND_HPP

#include "AutenticacaoCommand.hpp"

class LogoutCommand : public AutenticacaoCommand
{
public:
    LogoutCommand(IAutenticacaoService *service);
    void executar() override;
};

#endif // LOGOUTCOMMAND_HPP