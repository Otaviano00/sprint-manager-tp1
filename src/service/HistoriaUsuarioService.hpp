#ifndef HISTORIAUSUARIOSERVICE_HPP
#define HISTORIAUSUARIOSERVICE_HPP

#include <service/IHistoriaUsuarioService.hpp>
#include <repository/HistoriaDeUsuarioRepository.hpp>

class HistoriaUsuarioService : public IHistoriaUsuarioService
{
private:
    IAutenticacaoService *autenticacao;
    HistoriaDeUsuarioRepository *repository;

public:
    HistoriaUsuarioService();

    bool autenticarPapel(ServicoEnum servico) override;

    void criar(HistoriaDeUsuario &historiaUsuario) override;
    HistoriaDeUsuario listarPorId(int id) override;
    std::list<HistoriaDeUsuario> listar() override;
    void atualizar(HistoriaDeUsuario &historiaUsuario) override;
    void excluir(int id) override;
    void alterarEstado(std::string estado) override;
    void vincularPessoa(Pessoa &pessoa) override;
    void desvincularPessoa(Pessoa &pessoa) override;
    std::list<HistoriaDeUsuario> listarPorProjeto(Projeto &projeto) override;
    std::list<HistoriaDeUsuario> listarPorPlanoSprint(PlanoSprint &planoSprint) override;
    std::list<HistoriaDeUsuario> listarPorPessoa(Pessoa &pessoa) override;
    void moverParaSprint(PlanoSprint &planoSprint) override;
};

#endif // HISTORIAUSUARIOSERVICE_HPP
