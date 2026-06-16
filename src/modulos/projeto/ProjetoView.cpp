#include <modulos/projeto/ProjetoView.hpp>
#include <modulos/projeto/ProjetoService.hpp>
#include <dominios/Codigo.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Data.hpp>
#include <iostream>
#include <core/PanelBuilder.hpp>

ProjetoView::ProjetoView()
{
    service = new ProjetoService();
}

void ProjetoView::interfaceCriarProjeto()
{
    std::string strCodigo, strNome, strDataInicio, strDataFim;

    std::cout << "\n=== CRIAR NOVO PROJETO ===" << std::endl;

    std::cout << "Digite o código do projeto (2 letras maiúsculas e 3 dígitos): ";
    std::getline(std::cin, strCodigo);

    std::cout << "Digite o nome do projeto: ";
    std::getline(std::cin, strNome);

    std::cout << "Digite a data de início (DD/MM/YYYY): ";
    std::getline(std::cin, strDataInicio);

    std::cout << "Digite a data de término (DD/MM/YYYY): ";
    std::getline(std::cin, strDataFim);

    try
    {
        Codigo codigo;
        codigo.setValor(strCodigo);

        Nome nome;
        nome.setValor(strNome);

        Data dataInicio;
        dataInicio.setValor(strDataInicio);

        Data dataFim;
        dataFim.setValor(strDataFim);

        Projeto projeto;
        projeto.setCodigo(codigo);
        projeto.setNome(nome);
        projeto.setDataInicio(dataInicio);
        projeto.setDataFim(dataFim);

        if (!service->autenticarPapel(S5_CRIAR_PROJETO))
        {
            throw std::invalid_argument("Você não tem permissão para criar projetos.");
        }

        service->criar(projeto);
        std::cout << "\nProjeto criado com sucesso!" << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "\nErro ao criar projeto: " << e.what() << std::endl;
    }
}

void ProjetoView::interfaceLerProjeto()
{
    int id;
    std::cout << "\n=== LER PROJETO ===" << std::endl;
    std::cout << "Digite o ID do projeto: ";
    std::cin >> id;
    std::cin.ignore();

    try
    {
        if (!service->autenticarPapel(S6_LER_PROJETO))
        {
            throw std::invalid_argument("Você não tem permissão para ler projetos.");
        }

        Projeto projeto = service->listarPorId(id);
        std::cout << "\n--- Detalhes do Projeto ---" << std::endl;
        std::cout << "ID: " << projeto.getId() << std::endl;
        std::cout << "Código: " << projeto.getCodigo().getValor() << std::endl;
        std::cout << "Nome: " << projeto.getNome().getValor() << std::endl;
        std::cout << "Data de Início: " << projeto.getDataInicio().getValor() << std::endl;
        std::cout << "Data de Término: " << projeto.getDataFim().getValor() << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "\nErro ao ler projeto: " << e.what() << std::endl;
    }
}

void ProjetoView::interfaceListarProjetos()
{
    std::cout << "\n=== LISTAR PROJETOS ===" << std::endl;

    try
    {
        if (!service->autenticarPapel(S6_LER_PROJETO))
        {
            throw std::invalid_argument("Você não tem permissão para listar projetos.");
        }

        std::list<Projeto> projetos = service->listar();

        if (projetos.empty())
        {
            std::cout << "Nenhum projeto cadastrado." << std::endl;
        }
        else
        {
            std::cout << "\n--- Projetos Cadastrados ---" << std::endl;
            for (const auto &projeto : projetos)
            {
                std::cout << "ID: " << projeto.getId() 
                          << " | Código: " << projeto.getCodigo().getValor() << std::endl;
            }
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "\nErro ao listar projetos: " << e.what() << std::endl;
    }
}

void ProjetoView::interfaceAtualizarProjeto()
{
    int id;
    std::string strNome, strDataInicio, strDataFim;

    std::cout << "\n=== ATUALIZAR PROJETO ===" << std::endl;
    std::cout << "Digite o ID do projeto: ";
    std::cin >> id;
    std::cin.ignore();

    try
    {
        Projeto projeto = service->listarPorId(id);

        std::cout << "Digite o novo nome do projeto (atual: " << projeto.getNome().getValor() << "): ";
        std::getline(std::cin, strNome);

        std::cout << "Digite a nova data de início (atual: " << projeto.getDataInicio().getValor() << "): ";
        std::getline(std::cin, strDataInicio);

        std::cout << "Digite a nova data de término (atual: " << projeto.getDataFim().getValor() << "): ";
        std::getline(std::cin, strDataFim);

        if (!service->autenticarPapel(S7_ATUALIZAR_PROJETO))
        {
            throw std::invalid_argument("Você não tem permissão para atualizar projetos.");
        }

        if (!strNome.empty())
        {
            Nome nome;
            nome.setValor(strNome);
            projeto.setNome(nome);
        }

        if (!strDataInicio.empty())
        {
            Data dataInicio;
            dataInicio.setValor(strDataInicio);
            projeto.setDataInicio(dataInicio);
        }

        if (!strDataFim.empty())
        {
            Data dataFim;
            dataFim.setValor(strDataFim);
            projeto.setDataFim(dataFim);
        }

        service->atualizar(projeto);
        std::cout << "\nProjeto atualizado com sucesso!" << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "\nErro ao atualizar projeto: " << e.what() << std::endl;
    }
}

void ProjetoView::interfaceExcluirProjeto()
{
    int id;
    std::cout << "\n=== EXCLUIR PROJETO ===" << std::endl;
    std::cout << "Digite o ID do projeto a excluir: ";
    std::cin >> id;
    std::cin.ignore();

    try
    {
        if (!service->autenticarPapel(S8_EXCLUIR_PROJETO))
        {
            throw std::invalid_argument("Você não tem permissão para excluir projetos.");
        }

        service->excluir(id);
        std::cout << "\nProjeto excluído com sucesso!" << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "\nErro ao excluir projeto: " << e.what() << std::endl;
    }
}

void ProjetoView::executar()
{
    auto menuPrincipal = PanelBuilder::builder()
        ->withTitle("GERENCIAMENTO DE PROJETOS")
        ->withOptions(true)
        ->withZeroAction(true, "Retornar", nullptr)
        ->build();

    auto opcao1 = PanelBuilder::builder()
        ->withTitle("Criar Projeto")
        ->withAction([this]()
                     { this->interfaceCriarProjeto(); })
        ->withEnd(true)
        ->build();

    auto opcao2 = PanelBuilder::builder()
        ->withTitle("Ler Projeto")
        ->withAction([this]()
                     { this->interfaceLerProjeto(); })
        ->withEnd(true)
        ->build();

    auto opcao3 = PanelBuilder::builder()
        ->withTitle("Listar Projetos")
        ->withAction([this]()
                     { this->interfaceListarProjetos(); })
        ->withEnd(true)
        ->build();

    auto opcao4 = PanelBuilder::builder()
        ->withTitle("Atualizar Projeto")
        ->withAction([this]()
                     { this->interfaceAtualizarProjeto(); })
        ->withEnd(true)
        ->build();

    auto opcao5 = PanelBuilder::builder()
        ->withTitle("Excluir Projeto")
        ->withAction([this]()
                     { this->interfaceExcluirProjeto(); })
        ->withEnd(true)
        ->build();

    menuPrincipal->addOption(opcao1);
    menuPrincipal->addOption(opcao2);
    menuPrincipal->addOption(opcao3);
    menuPrincipal->addOption(opcao4);
    menuPrincipal->addOption(opcao5);

    menuPrincipal->showPanel();
    delete menuPrincipal;
}
