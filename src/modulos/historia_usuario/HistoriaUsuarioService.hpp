#ifndef HISTORIAUSUARIOSERVICE_HPP
#define HISTORIAUSUARIOSERVICE_HPP

#include <modulos/historia_usuario/IHistoriaUsuarioService.hpp>
#include <modulos/historia_usuario/HistoriaDeUsuarioRepository.hpp>
#include <modulos/plano_sprint/PlanoSprintRepository.hpp>
#include <modulos/pessoa/PessoaRepository.hpp>
#include <modulos/projeto/ProjetoRepository.hpp>

/**
 * @brief Implementa regras de negócio e persistência de HistoriaDeUsuario.
 */
class HistoriaUsuarioService : public IHistoriaUsuarioService
{
private:
    IAutenticacaoService *autenticacao;
    HistoriaDeUsuarioRepository *repository;
    PlanoSprintRepository *planoSprintRepository;
    PessoaRepository *pessoaRepository;

public:
    HistoriaUsuarioService();
    ~HistoriaUsuarioService();

    bool autenticarPapel(ServicoEnum servico) override;

    void criar(HistoriaDeUsuario &historiaUsuario) override;
    HistoriaDeUsuario listarPorId(int id) override;
    std::list<HistoriaDeUsuario> listar() override;
    void atualizar(HistoriaDeUsuario &historiaUsuario) override;
    void excluir(int id) override;

    void alterarEstado(int historiaId, std::string estado) override;
    void vincularPessoa(int historiaId, Pessoa &pessoa) override;
    void desvincularPessoa(int historiaId) override;

    std::list<HistoriaDeUsuario> listarPorProjeto(Projeto &projeto) override;
    std::list<HistoriaDeUsuario> listarPorPlanoSprint(PlanoSprint &planoSprint) override;
    std::list<HistoriaDeUsuario> listarPorPessoa(Pessoa &pessoa) override;
    void moverParaSprint(int historiaId, PlanoSprint &planoSprint) override;
};

#endif // HISTORIAUSUARIOSERVICE_HPP
