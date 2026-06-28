#ifndef EXCLUIRPESSOACOMMAND_HPP
#define EXCLUIRPESSOACOMMAND_HPP

#include <modulos/pessoa/commands/PessoaCommand.hpp>

class ExcluirPessoaCommand : public PessoaCommand
{
public:
    ExcluirPessoaCommand(IPessoaService *service);
    void executar() override;
};

#endif // EXCLUIRPESSOACOMMAND_HPP