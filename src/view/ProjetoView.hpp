#ifndef PROJETOVIEW_HPP
#define PROJETOVIEW_HPP

#include <view/IProjetoView.hpp>
#include <service/IProjetoService.hpp>
#include <panel/Panel.hpp>

/**
 * @brief Implementa a interface CLI para operações de projeto.
 */
class ProjetoView : public IProjetoView
{
private:
    IProjetoService *service;
    JustOptionsPanel *menuLocal;

    void interfaceCriarProjeto();
    void interfaceListarProjetos();
    void interfaceAtualizarProjeto();
    void interfaceExcluirProjeto();
    void interfaceListarProjetosPorPessoa();

public:
    /**
     * @brief Constrói o módulo de projetos e inicializa dependências.
     */
    ProjetoView();

    /**
     * @brief Exibe o menu de projetos e executa ações selecionadas.
     */
    void executar() override;
};

#endif // PROJETOVIEW_HPP
