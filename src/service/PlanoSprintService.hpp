#ifndef PLANOSPRINTSERVICE_HPP
#define PLANOSPRINTSERVICE_HPP

#include <service/IPlanoSprintService.hpp>
#include <service/IAutenticacaoService.hpp>
#include <repository/PlanoSprintRepository.hpp>

class PlanoSprintService : public IPlanoSprintService
{
private:
    IAutenticacaoService *autenticacao;
    PlanoSprintRepository *repository;

public:
    PlanoSprintService();

    bool autenticarPapel(ServicoEnum servico) override;

    void criar(PlanoSprint &planoSprint) override;
    PlanoSprint listarPorId(int id) override;
    std::list<PlanoSprint> listar() override;
    void atualizar(PlanoSprint &planoSprint) override;
    void excluir(int id) override;
    std::list<PlanoSprint> listarPorProjeto(Projeto &projeto) override;
};

#endif // PLANOSPRINTSERVICE_HPP
