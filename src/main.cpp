#include <iostream>
#include <modulos/mvc/IViewController.hpp>
#include <modulos/mvc/ViewController.hpp>
#include <modulos/pessoa/PessoaRepository.hpp>
#include <modulos/pessoa/Pessoa.hpp>

void gerarUsuarioTeste()
{
    const std::string emailTeste = "teste@unb.br";
    const std::string nomeTeste = "Usuario";
    const std::string senhaTeste = "A1b2C3";
    const std::string papelTeste = "PROPRIETARIO_DE_PRODUTO";

    PessoaRepository *pessoaRepository = new PessoaRepository();
    Email emailTesteDominio;
    emailTesteDominio.setValor(emailTeste);
    Pessoa *existente = pessoaRepository->findByEmail(emailTesteDominio);
    if (existente != nullptr)
    {
        delete existente;
        delete pessoaRepository;
        return;
    }

    Pessoa pessoaTeste;

    Email email;
    email.setValor(emailTeste);
    pessoaTeste.setEmail(email);

    Nome nome;
    nome.setValor(nomeTeste);
    pessoaTeste.setNome(nome);

    Senha senha;
    senha.setValor(senhaTeste);
    pessoaTeste.setSenha(senha);

    Papel papel;
    papel.setValor(papelTeste);
    pessoaTeste.setPapel(papel);

    pessoaRepository->save(pessoaTeste);
    delete pessoaRepository;
}

int main()
{

    gerarUsuarioTeste();

    IViewController *viewController = new ViewController();

    viewController->executar();

    delete viewController;

    return 0;
}