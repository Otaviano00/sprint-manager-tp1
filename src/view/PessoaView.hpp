#ifndef PESSOAVIEW_HPP
#define PESSOAVIEW_HPP

#include <view/IPessoaView.hpp>
#include <service/IPessoaService.hpp>
#include <panel/Panel.hpp>

/**
 * @brief Implementa a interface CLI para operações de pessoa.
 */
class PessoaView : public IPessoaView
{
private:
    IPessoaService *service;
    JustOptionsPanel *menuLocal;

    void interfaceCriarPessoa();
    void interfaceListarPessoas();
    void interfaceAtualizarPessoa();
    void interfaceExcluirPessoa();

public:
    /**
     * @brief Constrói o módulo de pessoas e inicializa dependências.
     */
    PessoaView();

    /**
     * @brief Exibe o menu de pessoas e executa ações selecionadas.
     */
    void executar() override;
};

#endif // PESSOAVIEW_HPP
