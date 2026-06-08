#ifndef IPESSOASERVICE_HPP
#define IPESSOASERVICE_HPP

#include <list>
#include <stdexcept>
#include <util/ServicoEnum.hpp>
#include <entidades/Pessoa.hpp>

class IPessoaService
{
public:
    virtual bool autenticarPapel(ServicoEnum servico) = 0;

    // CRUD
    virtual void criar(Pessoa &pessoa) = 0;
    virtual Pessoa listarPorId(int id) = 0;
    virtual std::list<Pessoa> listar() = 0;
    virtual void atualizar(Pessoa &pessoa) = 0;
    virtual void excluir(int id) = 0;

    virtual ~IPessoaService() = default;
};

#endif // IPESSOASERVICE_HPP