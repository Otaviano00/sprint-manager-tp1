#include <modulos/plano_sprint/commands/CriarPlanoSprintCommand.hpp>
#include <modulos/plano_sprint/PlanoSprint.hpp>
#include <modulos/projeto/commands/RecuperarProjetoCommand.hpp>
#include <dominios/Email.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Senha.hpp>
#include <dominios/Papel.hpp>
#include <iostream>
#include <string>

CriarPlanoSprintCommand::CriarPlanoSprintCommand(IPlanoSprintService *service) : PlanoSprintCommand(service) {}

void CriarPlanoSprintCommand::executar()
{
    PlanoSprint planoSprint;

    std::string codigoStr;
    std::cout << "Codigo: ";
    std::getline(std::cin, codigoStr);
    Codigo codigo;
    codigo.setValor(codigoStr);
    planoSprint.setCodigo(codigo);

    std::string nomeStr;
    std::cout << "Nome: ";
    std::getline(std::cin, nomeStr);
    Nome nome;
    nome.setValor(nomeStr);
    planoSprint.setNome(nome);

    std::string dataInicioStr;
    std::cout << "Data Inicio (dd/mm/aaaa): ";
    std::getline(std::cin, dataInicioStr);
    Data dataInicio;
    dataInicio.setValor(dataInicioStr);
    planoSprint.setDataInicio(dataInicio);

    std::string dataFimStr;
    std::cout << "Data Inicio (dd/mm/aaaa): ";
    std::getline(std::cin, dataFimStr);
    Data dataFim;
    dataFim.setValor(dataFimStr);
    planoSprint.setDataFim(dataFim);

    Projeto projeto = RecuperarProjetoCommand().getProjetoFromInput();
    planoSprint.setProjeto(projeto);

    try
    {
        service->criar(planoSprint);
    }
    catch (const std::invalid_argument &e)
    {
        throw std::invalid_argument("Erro ao criar plano de sprint: " + std::string(e.what()));
    }

    std::cout << std::endl
              << "Plano de Sprint cadastrada com sucesso!" << std::endl;
}