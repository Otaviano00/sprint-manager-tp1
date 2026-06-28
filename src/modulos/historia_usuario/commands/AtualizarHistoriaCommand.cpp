#include <modulos/historia_usuario/commands/AtualizarHistoriaCommand.hpp>
#include <modulos/historia_usuario/commands/RecuperarHistoriaCommand.hpp>
#include <iostream>

AtualizarHistoriaCommand::AtualizarHistoriaCommand(IHistoriaUsuarioService *service) : service(service) {}

void AtualizarHistoriaCommand::executar()
{
    RecuperarHistoriaCommand recCmd;
    HistoriaDeUsuario historia = recCmd.getHistoriaFromInput();

    std::string cod, tit, pap, aca, val, est_str, prio;

    std::cout << "Novo Codigo (" << historia.getCodigo().getValor() << "): ";
    std::getline(std::cin, cod);
    if (!cod.empty())
    {
        Codigo c;
        c.setValor(cod);
        historia.setCodigo(c);
    }

    std::cout << "Novo Titulo (" << historia.getTitulo().getValor() << "): ";
    std::getline(std::cin, tit);
    if (!tit.empty())
    {
        Texto t;
        t.setValor(tit);
        historia.setTitulo(t);
    }

    std::cout << "Como um (" << historia.getPapel().getValor() << "): ";
    std::getline(std::cin, pap);
    if (!pap.empty())
    {
        Texto p;
        p.setValor(pap);
        historia.setPapel(p);
    }

    std::cout << "Eu quero (" << historia.getAcao().getValor() << "): ";
    std::getline(std::cin, aca);
    if (!aca.empty())
    {
        Texto a;
        a.setValor(aca);
        historia.setAcao(a);
    }

    std::cout << "Para (" << historia.getValor().getValor() << "): ";
    std::getline(std::cin, val);
    if (!val.empty())
    {
        Texto v;
        v.setValor(val);
        historia.setValor(v);
    }

    std::cout << "Estimativa (" << historia.getEstimativa().getValor() << "): ";
    std::getline(std::cin, est_str);
    if (!est_str.empty())
    {
        Tempo t;
        t.setValor(std::stoi(est_str));
        historia.setEstimativa(t);
    }

    std::cout << "Prioridade (" << historia.getPrioridade().getValor() << "): ";
    std::getline(std::cin, prio);
    if (!prio.empty())
    {
        Prioridade p;
        p.setValor(prio);
        historia.setPrioridade(p);
    }

    service->atualizar(historia);
    std::cout << std::endl
              << "Historia atualizada com sucesso!" << std::endl;
}
