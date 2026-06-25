#include <modulos/pessoa/PessoaView.hpp>
#include <modulos/pessoa/PessoaService.hpp>
#include <modulos/pessoa/Pessoa.hpp>
#include <dominios/Email.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Senha.hpp>
#include <dominios/Papel.hpp>
#include <core/PanelBuilder.hpp>
#include <iostream>
#include <string>

PessoaView::PessoaView()
{
    service = new PessoaService();
}

PessoaView::~PessoaView()
{
    delete service;
}

void PessoaView::interfaceCriarPessoa()
{
    std::string nomeStr, emailStr, senhaStr, papelStr;

    std::cout << "Nome: ";
    std::getline(std::cin, nomeStr);

    std::cout << "Email: ";
    std::getline(std::cin, emailStr);

    std::cout << "Senha: ";
    std::getline(std::cin, senhaStr);

    std::cout << "Papel (DESENVOLVEDOR / MESTRE_SCRUM / PROPRIETARIO_DE_PRODUTO): ";
    std::getline(std::cin, papelStr);

    if (!service->autenticarPapel(S1_CRIAR_PESSOA))
    {
        throw std::invalid_argument("Você não tem permissão para criar pessoas.");
    }

    Pessoa pessoa;

    Nome nome;
    nome.setValor(nomeStr);
    pessoa.setNome(nome);

    Email email;
    email.setValor(emailStr);
    pessoa.setEmail(email);

    Senha senha;
    senha.setValor(senhaStr);
    pessoa.setSenha(senha);

    Papel papel;
    papel.setValor(papelStr);
    pessoa.setPapel(papel);

    service->criar(pessoa);

    std::cout << std::endl
              << "Pessoa cadastrada com sucesso!" << std::endl;
}

void PessoaView::interfaceListarPessoas()
{
    if (!service->autenticarPapel(S2_LISTAR_PESSOA))
    {
        throw std::invalid_argument("Você não tem permissão para listar pessoas.");
    }

    std::list<Pessoa> pessoas = service->listar();

    if (pessoas.empty())
    {
        std::cout << "Nenhuma pessoa cadastrada." << std::endl;
        return;
    }

    std::cout << "Pessoas cadastradas:" << std::endl;
    for (const auto &pessoa : pessoas)
    {
        std::cout << "- ID: " << pessoa.getId()
                  << " | Nome: " << pessoa.getNome().getValor()
                  << " | Email: " << pessoa.getEmail().getValor()
                  << " | Papel: " << pessoa.getPapel().getValor() << std::endl;
    }
}

void PessoaView::interfaceBuscarPessoa()
{
    std::string entradaId;
    std::cout << "ID da pessoa: ";
    std::getline(std::cin, entradaId);

    if (!service->autenticarPapel(S2_LER_PESSOA))
    {
        throw std::invalid_argument("Você não tem permissão para consultar pessoas.");
    }

    int id = std::stoi(entradaId);
    Pessoa pessoa = service->listarPorId(id);

    std::cout << "Pessoa encontrada:" << std::endl;
    std::cout << "- ID: " << pessoa.getId()
              << " | Nome: " << pessoa.getNome().getValor()
              << " | Email: " << pessoa.getEmail().getValor()
              << " | Papel: " << pessoa.getPapel().getValor() << std::endl;
}

void PessoaView::interfaceAtualizarPessoa()
{
    std::string entradaId, nomeStr, emailStr, senhaStr, papelStr;

    std::cout << "ID da pessoa: ";
    std::getline(std::cin, entradaId);

    std::cout << "Nome: ";
    std::getline(std::cin, nomeStr);

    std::cout << "Email: ";
    std::getline(std::cin, emailStr);

    std::cout << "Senha: ";
    std::getline(std::cin, senhaStr);

    std::cout << "Papel (DESENVOLVEDOR / MESTRE_SCRUM / PROPRIETARIO_DE_PRODUTO): ";
    std::getline(std::cin, papelStr);

    if (!service->autenticarPapel(S3_ATUALIZAR_PESSOA))
    {
        throw std::invalid_argument("Você não tem permissão para atualizar pessoas.");
    }

    int id = std::stoi(entradaId);
    Pessoa pessoa = service->listarPorId(id);

    Nome nome;
    nome.setValor(nomeStr);
    pessoa.setNome(nome);

    Email email;
    email.setValor(emailStr);
    pessoa.setEmail(email);

    Senha senha;
    senha.setValor(senhaStr);
    pessoa.setSenha(senha);

    Papel papel;
    papel.setValor(papelStr);
    pessoa.setPapel(papel);

    service->atualizar(pessoa);

    std::cout << std::endl
              << "Pessoa atualizada com sucesso!" << std::endl;
}

void PessoaView::interfaceExcluirPessoa()
{
    std::string entradaId;
    std::cout << "ID da pessoa: ";
    std::getline(std::cin, entradaId);

    if (!service->autenticarPapel(S4_EXCLUIR_PESSOA))
    {
        throw std::invalid_argument("Você não tem permissão para excluir pessoas.");
    }

    int id = std::stoi(entradaId);
    service->excluir(id);

    std::cout << std::endl
              << "Pessoa excluída com sucesso!" << std::endl;
}

void PessoaView::executar()
{
    auto painelCriar = PanelBuilder::builder()
                           ->withTitle("Cadastrar Pessoa")
                           ->withAction([this]()
                                        { this->interfaceCriarPessoa(); })
                           ->withEnd(true)
                           ->build();

    auto painelListar = PanelBuilder::builder()
                            ->withTitle("Listar Pessoas")
                            ->withAction([this]()
                                         { this->interfaceListarPessoas(); })
                            ->withEnd(true)
                            ->build();

    auto painelBuscar = PanelBuilder::builder()
                            ->withTitle("Buscar Pessoa")
                            ->withAction([this]()
                                         { this->interfaceBuscarPessoa(); })
                            ->withEnd(true)
                            ->build();

    auto painelAtualizar = PanelBuilder::builder()
                               ->withTitle("Atualizar Pessoa")
                               ->withAction([this]()
                                            { this->interfaceAtualizarPessoa(); })
                               ->withEnd(true)
                               ->build();

    auto painelExcluir = PanelBuilder::builder()
                             ->withTitle("Excluir Pessoa")
                             ->withAction([this]()
                                          { this->interfaceExcluirPessoa(); })
                             ->withEnd(true)
                             ->build();

    auto painelPessoas = PanelBuilder::builder()
                             ->withTitle("Gerenciar Pessoas")
                             ->withOptions(true)
                             ->withZeroAction(true, "Voltar")
                             ->build();

    painelPessoas->addOption(painelCriar);
    painelPessoas->addOption(painelListar);
    painelPessoas->addOption(painelBuscar);
    painelPessoas->addOption(painelAtualizar);
    painelPessoas->addOption(painelExcluir);

    painelPessoas->showPanel();

    delete painelPessoas;
    delete painelCriar;
    delete painelListar;
    delete painelBuscar;
    delete painelAtualizar;
    delete painelExcluir;
}
