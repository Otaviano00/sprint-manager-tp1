#include <modulos/pessoa/PessoaView.hpp>
#include <modulos/pessoa/PessoaService.hpp>

#include <dominios/Email.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Senha.hpp>
#include <dominios/Papel.hpp>

#include <core/PanelBuilder.hpp>

#include <iostream>

PessoaView::PessoaView()
{
    service = new PessoaService();
}

PessoaView::~PessoaView()
{
    delete service;
}

void PessoaView::executar()
{
    auto menuPessoa = PanelBuilder::builder()
                           ->withTitle("Gerenciar Pessoas")
                           ->withOptions(true)
                           ->withEnd(true)
                           ->build();

    menuPessoa->addOption(
        PanelBuilder::builder()
            ->withTitle("Criar Pessoa")
            ->withAction([this]()
                         { criarPessoa(); })
            ->build());

    menuPessoa->addOption(
        PanelBuilder::builder()
            ->withTitle("Listar Pessoas")
            ->withAction([this]()
                         { listarPessoas(); })
            ->build());

    menuPessoa->addOption(
        PanelBuilder::builder()
            ->withTitle("Atualizar Pessoa")
            ->withAction([this]()
                         { atualizarPessoa(); })
            ->build());

    menuPessoa->addOption(
        PanelBuilder::builder()
            ->withTitle("Excluir Pessoa")
            ->withAction([this]()
                         { excluirPessoa(); })
            ->build());

    menuPessoa->showPanel();

    delete menuPessoa;
}

void PessoaView::criarPessoa()
{
    try
    {
        std::string emailStr;
        std::string nomeStr;
        std::string senhaStr;
        std::string papelStr;

        std::cout << "Email: ";
        std::getline(std::cin, emailStr);

        std::cout << "Nome: ";
        std::getline(std::cin, nomeStr);

        std::cout << "Senha: ";
        std::getline(std::cin, senhaStr);

        std::cout << "Papel (DESENVOLVEDOR, MESTRE_SCRUM, PROPRIETARIO_DE_PRODUTO): ";
        std::getline(std::cin, papelStr);

        Email email;
        email.setValor(emailStr);

        Nome nome;
        nome.setValor(nomeStr);

        Senha senha;
        senha.setValor(senhaStr);

        Papel papel;
        papel.setValor(papelStr);

        Pessoa pessoa;

        pessoa.setEmail(email);
        pessoa.setNome(nome);
        pessoa.setSenha(senha);
        pessoa.setPapel(papel);

        service->criar(pessoa);

        std::cout << "Pessoa criada com sucesso." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void PessoaView::listarPessoas()
{
    try
    {
        auto pessoas = service->listar();

        for (auto &pessoa : pessoas)
        {
            std::cout << "ID: " << pessoa.getId() << std::endl;
            std::cout << "Nome: " << pessoa.getNome().getValor() << std::endl;
            std::cout << "Email: " << pessoa.getEmail().getValor() << std::endl;
            std::cout << "Papel: " << pessoa.getPapel().getValor() << std::endl;
            std::cout << "-----------------------------" << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void PessoaView::atualizarPessoa()
{
    std::cout << "Funcionalidade ainda nao implementada." << std::endl;
}

void PessoaView::excluirPessoa()
{
    try
    {
        long id;

        std::cout << "ID da pessoa: ";
        std::cin >> id;
        std::cin.ignore();

        service->excluir(id);

        std::cout << "Pessoa excluida com sucesso." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}