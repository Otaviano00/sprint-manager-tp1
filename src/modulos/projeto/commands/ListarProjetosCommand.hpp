#ifndef LISTARPROJETOSCOMMAND_HPP
#define LISTARPROJETOSCOMMAND_HPP

#include <modulos/projeto/commands/ProjetoCommand.hpp>

class ListarProjetosCommand : public ProjetoCommand
{
public:
    ListarProjetosCommand(IProjetoService *service);
    void executar() override;
};

#endif // LISTARPROJETOSCOMMAND_HPP