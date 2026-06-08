#ifndef PROJETOSERVICE_HPP
#define PROJETOSERVICE_HPP

#include <service/IProjetoService.hpp>
#include <service/IAutenticacaoService.hpp>
#include <repository/ProjetoRepository.hpp>

class ProjetoService : public IProjetoService
{
private:
    IAutenticacaoService *autenticacao;
    ProjetoRepository *repository;

public:
    ProjetoService();

    bool autenticarPapel(ServicoEnum servico) override;

    void criar(Projeto &projeto) override;
    Projeto listarPorId(int id) override;
    std::list<Projeto> listar() override;
    void atualizar(Projeto &projeto) override;
    void excluir(int id) override;
    std::list<Projeto> listarPorPessoa(Pessoa &pessoa) override;
};

#endif // PROJETOSERVICE_HPP
