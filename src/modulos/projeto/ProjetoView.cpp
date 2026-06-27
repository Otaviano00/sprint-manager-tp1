#include <modulos/projeto/ProjetoView.hpp>
#include <modulos/projeto/ProjetoService.hpp>
#include <modulos/projeto/Projeto.hpp>
#include <dominios/Codigo.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Data.hpp>
#include <core/PanelBuilder.hpp>
#include <iostream>
#include <string>

ProjetoView::ProjetoView()
{
    service = new ProjetoService();
}

ProjetoView::~ProjetoView()
{
    delete service;
}

void ProjetoView::interfaceCriarProjeto()
{
    std::string codigoStr, nomeStr, dataInicioStr, dataFimStr, pessoaIdStr;

    std::cout << "Codigo: ";
    std::getline(std::cin, codigoStr);

    std::cout << "Nome: ";
    std::getline(std::cin, nomeStr);

    std::cout << "Data de inicio (dd/mm/aaaa): ";
    std::getline(std::cin, dataInicioStr);

    std::cout << "Data de fim (dd/mm/aaaa): ";
    std::getline(std::cin, dataFimStr);

    std::cout << "ID da pessoa associada: ";
    std::getline(std::cin, pessoaIdStr);

    Projeto projeto;

    Codigo codigo;
    codigo.setValor(codigoStr);
    projeto.setCodigo(codigo);

    Nome nome;
    nome.setValor(nomeStr);
    projeto.setNome(nome);

    Data dataInicio;
    dataInicio.setValor(dataInicioStr);
    projeto.setDataInicio(dataInicio);

    Data dataFim;
    dataFim.setValor(dataFimStr);
    projeto.setDataFim(dataFim);

    Pessoa pessoa(std::stoi(pessoaIdStr));
    projeto.setPessoa(pessoa);

    service->criar(projeto);

    std::cout << std::endl
              << "Projeto cadastrado com sucesso!" << std::endl;
}

void ProjetoView::interfaceListarProjetos()
{
    std::list<Projeto> projetos = service->listar();

    if (projetos.empty())
    {
        std::cout << "Nenhum projeto cadastrado." << std::endl;
        return;
    }

    std::cout << "Projetos cadastrados:" << std::endl;
    for (const auto &projeto : projetos)
    {
        std::cout << "- ID: " << projeto.getId()
                  << " | Codigo: " << projeto.getCodigo().getValor()
                  << " | Nome: " << projeto.getNome().getValor()
                  << " | Pessoa: " << projeto.getPessoa().getId() << std::endl;
    }
}

void ProjetoView::interfaceBuscarProjeto()
{
    std::string entradaId;
    std::cout << "ID do projeto: ";
    std::getline(std::cin, entradaId);

    Projeto projeto = service->listarPorId(std::stoi(entradaId));

    std::cout << "Projeto encontrado:" << std::endl;
    std::cout << "- ID: " << projeto.getId()
              << " | Codigo: " << projeto.getCodigo().getValor()
              << " | Nome: " << projeto.getNome().getValor()
              << " | Pessoa: " << projeto.getPessoa().getId() << std::endl;
}

void ProjetoView::interfaceAtualizarProjeto()
{
    std::string entradaId, codigoStr, nomeStr, dataInicioStr, dataFimStr, pessoaIdStr;

    std::cout << "ID do projeto: ";
    std::getline(std::cin, entradaId);

    std::cout << "Codigo: ";
    std::getline(std::cin, codigoStr);

    std::cout << "Nome: ";
    std::getline(std::cin, nomeStr);

    std::cout << "Data de inicio (dd/mm/aaaa): ";
    std::getline(std::cin, dataInicioStr);

    std::cout << "Data de fim (dd/mm/aaaa): ";
    std::getline(std::cin, dataFimStr);

    std::cout << "ID da pessoa associada: ";
    std::getline(std::cin, pessoaIdStr);

    Projeto projeto = service->listarPorId(std::stoi(entradaId));

    Codigo codigo;
    codigo.setValor(codigoStr);
    projeto.setCodigo(codigo);

    Nome nome;
    nome.setValor(nomeStr);
    projeto.setNome(nome);

    Data dataInicio;
    dataInicio.setValor(dataInicioStr);
    projeto.setDataInicio(dataInicio);

    Data dataFim;
    dataFim.setValor(dataFimStr);
    projeto.setDataFim(dataFim);

    Pessoa pessoa(std::stoi(pessoaIdStr));
    projeto.setPessoa(pessoa);

    service->atualizar(projeto);

    std::cout << std::endl
              << "Projeto atualizado com sucesso!" << std::endl;
}

void ProjetoView::interfaceExcluirProjeto()
{
    std::string entradaId;
    std::cout << "ID do projeto: ";
    std::getline(std::cin, entradaId);

    service->excluir(std::stoi(entradaId));

    std::cout << std::endl
              << "Projeto excluído com sucesso!" << std::endl;
}

void ProjetoView::executar()
{
    Panel *painelCriar = nullptr;
    if (service->autenticarPapel(S5_CRIAR_PROJETO))
    {
        painelCriar = PanelBuilder::builder()
                          ->withTitle("Cadastrar Projeto")
                          ->withAction([this]()
                                       { this->interfaceCriarProjeto(); })
                          ->withEnd(true)
                          ->build();
    }

    Panel *painelListar = nullptr;
    if (service->autenticarPapel(S6_LER_PROJETO))
    {
        painelListar = PanelBuilder::builder()
                           ->withTitle("Listar Projetos")
                           ->withAction([this]()
                                        { this->interfaceListarProjetos(); })
                           ->withEnd(true)
                           ->build();
    }

    Panel *painelBuscar = nullptr;
    if (service->autenticarPapel(S6_LER_PROJETO))
    {
        painelBuscar = PanelBuilder::builder()
                           ->withTitle("Buscar Projeto")
                           ->withAction([this]()
                                        { this->interfaceBuscarProjeto(); })
                           ->withEnd(true)
                           ->build();
    }

    Panel *painelAtualizar = nullptr;
    if (service->autenticarPapel(S7_ATUALIZAR_PROJETO))
    {
        painelAtualizar = PanelBuilder::builder()
                              ->withTitle("Atualizar Projeto")
                              ->withAction([this]()
                                           { this->interfaceAtualizarProjeto(); })
                              ->withEnd(true)
                              ->build();
    }

    Panel *painelExcluir = nullptr;
    if (service->autenticarPapel(S8_EXCLUIR_PROJETO))
    {
        painelExcluir = PanelBuilder::builder()
                            ->withTitle("Excluir Projeto")
                            ->withAction([this]()
                                         { this->interfaceExcluirProjeto(); })
                            ->withEnd(true)
                            ->build();
    }

    auto painelProjetos = PanelBuilder::builder()
                              ->withTitle("Gerenciar Projetos")
                              ->withOptions(true)
                              ->withZeroAction(true, "Voltar")
                              ->build();

    if (painelCriar != nullptr)
        painelProjetos->addOption(painelCriar);
    if (painelListar != nullptr)
        painelProjetos->addOption(painelListar);
    if (painelBuscar != nullptr)
        painelProjetos->addOption(painelBuscar);
    if (painelAtualizar != nullptr)
        painelProjetos->addOption(painelAtualizar);
    if (painelExcluir != nullptr)
        painelProjetos->addOption(painelExcluir);

    painelProjetos->showPanel();

    delete painelProjetos;
    delete painelCriar;
    delete painelListar;
    delete painelBuscar;
    delete painelAtualizar;
    delete painelExcluir;
}
