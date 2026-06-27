#ifndef BUSCARPESSOACOMMAND_HPP
#define BUSCARPESSOACOMMAND_HPP

#include "PessoaCommand.hpp"

class BuscarPessoaCommand : public PessoaCommand
{
public:
    BuscarPessoaCommand(IPessoaService *service);
    void executar() override;
};

#endif // BUSCARPESSOACOMMAND_HPP