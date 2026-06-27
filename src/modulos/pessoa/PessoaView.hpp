#ifndef PESSOAVIEW_HPP
#define PESSOAVIEW_HPP

#include <modulos/pessoa/IPessoaView.hpp>
#include <modulos/pessoa/IPessoaService.hpp>
#include <core/Panel.hpp>

/**
 * @brief Implementa a interface CLI para operações de pessoa.
 */
class PessoaView : public IPessoaView
{
private:
    IPessoaService *service;

public:
    /**
     * @brief Constrói o módulo de pessoas e inicializa dependências.
     */
    PessoaView();

    /**
     * @brief Destrói o módulo de pessoas e libera dependências.
     */
    ~PessoaView();

    /**
     * @brief Exibe o menu de pessoas e executa ações selecionadas.
     */
    void executar() override;
};

#endif // PESSOAVIEW_HPP
