#ifndef LISTARPROJETOSPESSOACOMMAND_HPP
#define LISTARPROJETOSPESSOACOMMAND_HPP

#include <modulos/projeto/commands/ProjetoCommand.hpp>

class ListarProjetosPessoaCommand : public ProjetoCommand
{
public:
    ListarProjetosPessoaCommand(IProjetoService *service);
    void executar() override;
};

#endif // LISTARPROJETOSPESSOACOMMAND_HPP