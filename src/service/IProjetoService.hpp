#ifndef IPROJETOSERVICE_HPP
#define IPROJETOSERVICE_HPP

#include <list>
#include <stdexcept>
#include <util/ServicoEnum.hpp>
#include <entidades/Projeto.hpp>
#include <entidades/Pessoa.hpp>
#include <dominios/Papel.hpp>

class IProjetoService
{
public:
    virtual bool autenticarPapel(ServicoEnum servico) = 0;

    // CRUD
    virtual void criar(Projeto &projeto) = 0;
    virtual Projeto listarPorId(int id) = 0;
    virtual std::list<Projeto> listar() = 0;
    virtual void atualizar(Projeto &projeto) = 0;
    virtual void excluir(int id) = 0;

    // Relacionamentos
    virtual std::list<Projeto> listarPorPessoa(Pessoa &pessoa) = 0;

    virtual ~IProjetoService() = default;
};

#endif // IPROJETOSERVICE_HPP