#ifndef PROJETOVIEW_HPP
#define PROJETOVIEW_HPP

#include <modulos/projeto/IProjetoView.hpp>
#include <modulos/projeto/IProjetoService.hpp>
#include <core/Panel.hpp>

/**
 * @brief Implementa a interface CLI para operações de projeto.
 */
class ProjetoView : public IProjetoView
{
private:
    IProjetoService *service;

public:
    /**
     * @brief Constrói o módulo de projetos e inicializa dependências.
     */
    ProjetoView();
    ~ProjetoView();

    /**
     * @brief Exibe o menu de projetos e executa ações selecionadas.
     */
    void executar() override;

private:
    void interfaceCriarProjeto();
    void interfaceListarProjetos();
    void interfaceBuscarProjeto();
    void interfaceAtualizarProjeto();
    void interfaceExcluirProjeto();
};

#endif // PROJETOVIEW_HPP
