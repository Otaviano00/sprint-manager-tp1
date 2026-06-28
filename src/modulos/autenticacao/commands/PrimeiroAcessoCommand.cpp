#include "PrimeiroAcessoCommand.hpp"
#include <modulos/pessoa/Pessoa.hpp>
#include <dominios/Email.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Senha.hpp>
#include <dominios/Papel.hpp>
#include <iostream>
#include <string>

PrimeiroAcessoCommand::PrimeiroAcessoCommand(IAutenticacaoService *service, IPessoaService *pessoaService) : AutenticacaoCommand(service, pessoaService) {}

void PrimeiroAcessoCommand::executar()
{
    Pessoa pessoa;

    std::string nomeStr;
    std::cout << "Nome: ";
    std::getline(std::cin, nomeStr);
    Nome nome;
    nome.setValor(nomeStr);
    pessoa.setNome(nome);

    std::string emailStr;
    std::cout << "Email: ";
    std::getline(std::cin, emailStr);
    Email email;
    email.setValor(emailStr);
    pessoa.setEmail(email);

    std::string senhaStr;
    std::cout << "Senha: ";
    std::getline(std::cin, senhaStr);
    Senha senha;
    senha.setValor(senhaStr);
    pessoa.setSenha(senha);

    std::string papelStr;
    std::cout << "Papel (DESENVOLVEDOR / MESTRE_SCRUM / PROPRIETARIO_DE_PRODUTO): ";
    std::getline(std::cin, papelStr);
    Papel papel;
    papel.setValor(papelStr);
    pessoa.setPapel(papel);

    pessoaService->criar(pessoa);

    std::cout << std::endl
              << "Conta criada com sucesso! Faça login para continuar." << std::endl;
}