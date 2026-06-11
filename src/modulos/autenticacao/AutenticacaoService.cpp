#include <modulos/autenticacao/AutenticacaoService.hpp>
#include <modulos/pessoa/Pessoa.hpp>
#include <dominios/Email.hpp>
#include <dominios/Senha.hpp>

bool AutenticacaoService::login(std::string email, std::string senha)
{
    Email emailDominio;
    emailDominio.setValor(email);

    Senha senhaDominio;
    senhaDominio.setValor(senha);

    pessoa = pessoaRepository->findByEmailAndSenha(emailDominio, senhaDominio);
    return pessoa != nullptr;
}

bool AutenticacaoService::isLoggedIn()
{
    return pessoa != nullptr;
}

void AutenticacaoService::logout()
{
    if (pessoa != nullptr)
    {
        delete pessoa;
        pessoa = nullptr;
    }
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
