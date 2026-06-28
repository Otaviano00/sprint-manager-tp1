#ifndef CRIARPESSOACOMMAND_HPP
#define CRIARPESSOACOMMAND_HPP

#include <modulos/pessoa/commands/PessoaCommand.hpp>

class CriarPessoaCommand : public PessoaCommand
{
public:
    CriarPessoaCommand(IPessoaService *service);
    void executar() override;
};

#endif // CRIARPESSOACOMMAND_HPP