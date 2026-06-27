#ifndef CRIARPESSOACOMMAND_HPP
#define CRIARPESSOACOMMAND_HPP

#include "PessoaCommand.hpp"

class CriarPessoaCommand : public PessoaCommand
{
public:
    CriarPessoaCommand(IPessoaService *service);
    void executar() override;
};

#endif // CRIARPESSOACOMMAND_HPP