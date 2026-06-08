#include <modulos/autenticacao/AutenticacaoService.hpp>
#include <modulos/pessoa/Pessoa.hpp>

bool AutenticacaoService::autenticarLogin(std::string email, std::string senha)
{
    if (email == "" || senha == "")
    {
        return false;
    }
    return true;
}

PapelEnum AutenticacaoService::getPapel()
{
    if (pessoa == nullptr)
    {
        throw std::invalid_argument("Usuário não autenticado");
    }

    if (pessoa->getPapel().getValor() == "DESENVOLVEDOR")
        return PapelEnum::DESENVOLVEDOR;
    if (pessoa->getPapel().getValor() == "MESTRE_SCRUM")
        return PapelEnum::MESTRE_SCRUM;
    if (pessoa->getPapel().getValor() == "PROPRIETARIO_DE_PRODUTO")
        return PapelEnum::PROPRIETARIO_DE_PRODUTO;

    throw std::invalid_argument("Papel desconhecido");
}
