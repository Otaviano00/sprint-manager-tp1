#ifndef ATUALIZARPESSOACOMMAND_HPP
#define ATUALIZARPESSOACOMMAND_HPP

#include <modulos/pessoa/commands/PessoaCommand.hpp>

class AtualizarPessoaCommand : public PessoaCommand
{
public:
    AtualizarPessoaCommand(IPessoaService *service);
    void executar() override;
};

#endif // ATUALIZARPESSOACOMMAND_HPP