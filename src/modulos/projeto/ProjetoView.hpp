#ifndef PROJETOVIEW_HPP
#define PROJETOVIEW_HPP

#include <modulos/projeto/IProjetoView.hpp>
#include <modulos/projeto/IProjetoService.hpp>
#include <core/Panel.hpp>

/**
 * @brief Implementa a interface CLI para operações de projeto.
 *
 * Responsável por gerenciar a interação com o usuário para criar, ler,
 * atualizar e excluir projetos. Valida os dados de entrada através dos
 * domínios e delega operações de negócio ao ProjetoService.
 */
class ProjetoView : public IProjetoView
{
private:
    IProjetoService *service;

    /**
     * @brief Interface para criar um novo projeto.
     *
     * Solicita ao usuário os dados do projeto (código, nome, datas),
     * valida os dados através dos domínios e cria o projeto via serviço.
     */
    void interfaceCriarProjeto();

    /**
     * @brief Interface para ler um projeto específico.
     *
     * Solicita o ID do projeto e exibe todas as informações do projeto.
     */
    void interfaceLerProjeto();

    /**
     * @brief Interface para listar todos os projetos cadastrados.
     *
     * Exibe uma lista resumida com ID e código de todos os projetos.
     */
    void interfaceListarProjetos();

    /**
     * @brief Interface para atualizar um projeto existente.
     *
     * Solicita o ID do projeto e permite atualizar nome e datas.
     * Não permite alteração do código (chave primária).
     */
    void interfaceAtualizarProjeto();

    /**
     * @brief Interface para excluir um projeto.
     *
     * Solicita confirmação do ID do projeto a ser excluído.
     */
    void interfaceExcluirProjeto();

public:
    /**
     * @brief Constrói o módulo de projetos e inicializa dependências.
     */
    ProjetoView();

    /**
     * @brief Exibe o menu de projetos e executa ações selecionadas.
     *
     * Apresenta um painel com opções para criar, ler, atualizar e excluir projetos,
     * permitindo navegação pelo usuário.
     */
    void executar() override;
};

#endif // PROJETOVIEW_HPP
