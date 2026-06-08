#ifndef IHISTORIAUSUARIOSERVICE_HPP
#define IHISTORIAUSUARIOSERVICE_HPP

#include <list>
#include <string>
#include <stdexcept>
#include <service/IAutenticacaoService.hpp>
#include <util/ServicoEnum.hpp>
#include <entidades/HistoriaDeUsuario.hpp>
#include <entidades/Pessoa.hpp>
#include <entidades/Projeto.hpp>
#include <entidades/PlanoSprint.hpp>
#include <dominios/Papel.hpp>

class IHistoriaUsuarioService
{
protected:
    IAutenticacaoService *autenticacao;

public:
    virtual bool autenticarPapel(ServicoEnum servico) = 0;

    // CRUD
    virtual void criar(HistoriaDeUsuario &historiaUsuario) = 0;
    virtual HistoriaDeUsuario listarPorId(int id) = 0;
    virtual std::list<HistoriaDeUsuario> listar() = 0;
    virtual void atualizar(HistoriaDeUsuario &historiaUsuario) = 0;
    virtual void excluir(int id) = 0;

    virtual void alterarEstado(std::string estado) = 0;

    // Relacionamentos
    virtual void vincularPessoa(Pessoa &pessoa) = 0;
    virtual void desvincularPessoa(Pessoa &pessoa) = 0;

    virtual std::list<HistoriaDeUsuario> listarPorProjeto(Projeto &projeto) = 0;
    virtual std::list<HistoriaDeUsuario> listarPorPlanoSprint(PlanoSprint &planoSprint) = 0;
    virtual std::list<HistoriaDeUsuario> listarPorPessoa(Pessoa &pessoa) = 0;

    virtual void moverParaSprint(PlanoSprint &planoSprint) = 0;

    virtual ~IHistoriaUsuarioService() = default;
};

#endif // IHISTORIAUSUARIOSERVICE_HPP
