#include <modulos/projeto/Projeto.hpp>
#include <modulos/projeto/commands/AtualizarProjetoCommand.hpp>
#include <modulos/projeto/commands/RecuperarProjetoCommand.hpp>
#include <dominios/Codigo.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Data.hpp>
#include <iostream>
#include <string>

AtualizarProjetoCommand::AtualizarProjetoCommand(IProjetoService *service) : ProjetoCommand(service) {}

void AtualizarProjetoCommand::executar()
{
    Projeto projeto = RecuperarProjetoCommand().getProjetoFromInput();

    std::string codigoStr;
    std::cout << "Codigo: ";
    std::getline(std::cin, codigoStr);

    if (!codigoStr.empty())
    {
        Codigo codigo;
        codigo.setValor(codigoStr);
        projeto.setCodigo(codigo);
    }

    std::string nomeStr;
    std::cout << "Nome: ";
    std::getline(std::cin, nomeStr);

    if (!nomeStr.empty())
    {
        Nome nome;
        nome.setValor(nomeStr);
        projeto.setNome(nome);
    }

    std::string dataInicioStr;
    std::cout << "Data de inicio (dd/mm/aaaa): ";
    std::getline(std::cin, dataInicioStr);

    if (!dataInicioStr.empty())
    {
        Data dataInicio;
        dataInicio.setValor(dataInicioStr);
        projeto.setDataInicio(dataInicio);
    }

    std::string dataFimStr;
    std::cout << "Data de fim (dd/mm/aaaa): ";
    std::getline(std::cin, dataFimStr);

    if (!dataFimStr.empty())
    {
        Data dataFim;
        dataFim.setValor(dataFimStr);
        projeto.setDataFim(dataFim);
    }

    std::string pessoaIdStr;
    std::cout << "ID da pessoa associada: ";
    std::getline(std::cin, pessoaIdStr);

    if (!pessoaIdStr.empty())
    {
        try
        {
            Pessoa pessoa(std::stoi(pessoaIdStr));
            projeto.setPessoa(pessoa);
        }
        catch (const std::invalid_argument &e)
        {
            throw std::invalid_argument("Erro ao atualizar projeto: " + std::string(e.what()));
        }
    }

    try
    {
        service->atualizar(projeto);
    }
    catch (const std::invalid_argument &e)
    {
        throw std::invalid_argument("Erro ao atualizar projeto: " + std::string(e.what()));
    }

    std::cout << std::endl
              << "Projeto atualizado com sucesso!" << std::endl;
}