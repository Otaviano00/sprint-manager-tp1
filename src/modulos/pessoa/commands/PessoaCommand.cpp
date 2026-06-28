#include <modulos/pessoa/commands/PessoaCommand.hpp>
#include <iostream>
#include <string>

PessoaCommand::PessoaCommand(IPessoaService *service) : service(service) {}
