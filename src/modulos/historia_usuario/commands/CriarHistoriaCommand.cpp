#include <modulos/historia_usuario/commands/CriarHistoriaCommand.hpp>
#include <modulos/projeto/commands/RecuperarProjetoCommand.hpp>
#include <dominios/Codigo.hpp>
#include <dominios/Texto.hpp>
#include <dominios/Tempo.hpp>
#include <dominios/Prioridade.hpp>
#include <iostream>

CriarHistoriaCommand::CriarHistoriaCommand(IHistoriaUsuarioService *service) : service(service) {}

void CriarHistoriaCommand::executar()
{
    RecuperarProjetoCommand recProjCmd;
    Projeto projeto = recProjCmd.getProjetoFromInput();

    HistoriaDeUsuario historia;
    historia.setProjeto(projeto);

    std::string cod, tit, pap, aca, val, est_str, prio;

    std::cout << "Codigo (Ex: AB123): ";
    std::getline(std::cin, cod);
    Codigo codigo;
    codigo.setValor(cod);
    historia.setCodigo(codigo);

    std::cout << "Titulo: ";
    std::getline(std::cin, tit);
    Texto titulo;
    titulo.setValor(tit);
    historia.setTitulo(titulo);

    std::cout << "Como um (Papel): ";
    std::getline(std::cin, pap);
    Texto papel;
    papel.setValor(pap);
    historia.setPapel(papel);

    std::cout << "Eu quero (Acao): ";
    std::getline(std::cin, aca);
    Texto acao;
    acao.setValor(aca);
    historia.setAcao(acao);

    std::cout << "Para (Valor): ";
    std::getline(std::cin, val);
    Texto valor;
    valor.setValor(val);
    historia.setValor(valor);

    std::cout << "Estimativa (Tempo em dias): ";
    std::getline(std::cin, est_str);
    Tempo estimativa;
    estimativa.setValor(std::stoi(est_str));
    historia.setEstimativa(estimativa);

    std::cout << "Prioridade (ALTA, MEDIA, BAIXA): ";
    std::getline(std::cin, prio);
    Prioridade prioridade;
    prioridade.setValor(prio);
    historia.setPrioridade(prioridade);

    service->criar(historia);
    std::cout << "Historia de usuario criada com sucesso!" << std::endl;
}
