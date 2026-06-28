#ifndef RECUPERARPESSOACOMMAND_HPP
#define RECUPERARPESSOACOMMAND_HPP

#include <modulos/pessoa/Pessoa.hpp>

class RecuperarPessoaCommand
{
public:
    RecuperarPessoaCommand() {}
    Pessoa getPessoaFromInput();
};

#endif // RecuperarPessoaCommand_HPP