#include "AutenticacaoCommand.hpp"

AutenticacaoCommand::AutenticacaoCommand(IAutenticacaoService *service, IPessoaService *pessoaService) : service(service), pessoaService(pessoaService) {}