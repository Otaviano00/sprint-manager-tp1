#include "LoginCommand.hpp"
#include <dominios/Email.hpp>
#include <dominios/Senha.hpp>
#include <iostream>
#include <string>

LoginCommand::LoginCommand(IAutenticacaoService *service) : AutenticacaoCommand(service) {}

void LoginCommand::executar()
{
    std::string email;
    std::cout << "Digite seu email: ";
    std::getline(std::cin, email);

    Email emailObj;
    emailObj.setValor(email);

    std::string senha;
    std::cout << "Digite sua senha: ";
    std::getline(std::cin, senha);

    Senha senhaObj;
    senhaObj.setValor(senha);

    if (service->login(emailObj, senhaObj))
    {
        std::cout << std::endl
                  << "Login bem-sucedido!" << std::endl;
    }
    else
    {
        throw std::invalid_argument("Email ou senha não encontrados.");
    }
}