#include <modulos/pessoa/commands/AtualizarPessoaCommand.hpp>
#include <modulos/pessoa/commands/RecuperarPessoaCommand.hpp>
#include <modulos/pessoa/Pessoa.hpp>
#include <dominios/Email.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Senha.hpp>
#include <dominios/Papel.hpp>
#include <iostream>
#include <string>

AtualizarPessoaCommand::AtualizarPessoaCommand(IPessoaService *service) : PessoaCommand(service) {}

void AtualizarPessoaCommand::executar()
{
    Pessoa pessoa = RecuperarPessoaCommand().getPessoaFromInput();

    std::string nomeStr;
    std::cout << "Nome: ";
    std::getline(std::cin, nomeStr);

    if (!nomeStr.empty())
    {
        Nome nome;
        nome.setValor(nomeStr);
        pessoa.setNome(nome);
    }

    std::string emailStr;
    std::cout << "Email: ";
    std::getline(std::cin, emailStr);

    if (!emailStr.empty())
    {
        Email email;
        email.setValor(emailStr);
        pessoa.setEmail(email);
    }

    std::string senhaStr;
    std::cout << "Senha: ";
    std::getline(std::cin, senhaStr);

    if (!senhaStr.empty())
    {
        Senha senha;
        senha.setValor(senhaStr);
        pessoa.setSenha(senha);
    }

    std::string papelStr;
    std::cout << "Papel (DESENVOLVEDOR / MESTRE_SCRUM / PROPRIETARIO_DE_PRODUTO): ";
    std::getline(std::cin, papelStr);

    if (!papelStr.empty())
    {
        Papel papel;
        papel.setValor(papelStr);
        pessoa.setPapel(papel);
    }

    try
    {
        service->atualizar(pessoa);
    }
    catch (const std::invalid_argument &e)
    {
        throw std::invalid_argument("Erro ao atualizar pessoa: " + std::string(e.what()));
    }

    std::cout << std::endl
              << "Pessoa atualizada com sucesso!" << std::endl;
}