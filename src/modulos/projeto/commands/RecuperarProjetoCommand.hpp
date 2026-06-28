#ifndef RECUPERARPROJETOCOMMAND_HPP
#define RECUPERARPROJETOCOMMAND_HPP

#include <modulos/projeto/Projeto.hpp>

class RecuperarProjetoCommand
{
public:
    RecuperarProjetoCommand() {}
    Projeto getProjetoFromInput();
};

#endif // RECUPERARPROJETOCOMMAND_HPP