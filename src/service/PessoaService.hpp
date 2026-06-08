#ifndef PESSOASERVICE_HPP
#define PESSOASERVICE_HPP

#include <service/IPessoaService.hpp>
#include <service/IAutenticacaoService.hpp>
#include <repository/PessoaRepository.hpp>

class PessoaService : public IPessoaService
{
private:
    IAutenticacaoService *autenticacao;
    PessoaRepository *repository;

public:
    PessoaService();

    bool autenticarPapel(ServicoEnum servico) override;

    void criar(Pessoa &pessoa) override;
    Pessoa listarPorId(int id) override;
    std::list<Pessoa> listar() override;
    void atualizar(Pessoa &pessoa) override;
    void excluir(int id) override;
};

#endif // PESSOASERVICE_HPP
