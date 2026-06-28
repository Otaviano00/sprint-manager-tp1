#include <modulos/plano_sprint/commands/AtualizarPlanoSprintCommand.hpp>
#include <modulos/plano_sprint/PlanoSprint.hpp>
#include <modulos/projeto/commands/RecuperarProjetoCommand.hpp>
#include <dominios/Email.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Senha.hpp>
#include <dominios/Papel.hpp>
#include <iostream>
#include <string>

AtualizarPlanoSprintCommand::AtualizarPlanoSprintCommand(IPlanoSprintService *service) : PlanoSprintCommand(service) {}

void AtualizarPlanoSprintCommand::executar()
{
    PlanoSprint planoSprint;

    std::string codigoStr;
    std::cout << "Codigo: ";
    std::getline(std::cin, codigoStr);

    if (!codigoStr.empty())
    {
        Codigo codigo;
        codigo.setValor(codigoStr);
        planoSprint.setCodigo(codigo);
    }

    std::string nomeStr;
    std::cout << "Nome: ";
    std::getline(std::cin, nomeStr);

    if (!nomeStr.empty())
    {
        Nome nome;
        nome.setValor(nomeStr);
        planoSprint.setNome(nome);
    }

    std::string dataInicioStr;
    std::cout << "Data Inicio (dd/mm/aaaa): ";
    std::getline(std::cin, dataInicioStr);

    if (!dataInicioStr.empty())
    {
        Data dataInicio;
        dataInicio.setValor(dataInicioStr);
        planoSprint.setDataInicio(dataInicio);
    }

    std::string dataFimStr;
    std::cout << "Data Inicio (dd/mm/aaaa): ";
    std::getline(std::cin, dataFimStr);

    if (!dataFimStr.empty())
    {
        Data dataFim;
        dataFim.setValor(dataFimStr);
        planoSprint.setDataFim(dataFim);
    }

    try
    {
        Projeto projeto = RecuperarProjetoCommand().getProjetoFromInput();
        planoSprint.setProjeto(projeto);
    }
    catch (const std::invalid_argument &e)
    {
    }

    try
    {
        service->atualizar(planoSprint);
    }
    catch (const std::invalid_argument &e)
    {
        throw std::invalid_argument("Erro ao atualizar plano de sprint: " + std::string(e.what()));
    }

    std::cout << std::endl
              << "Plano de Sprint atualizado com sucesso!" << std::endl;
}