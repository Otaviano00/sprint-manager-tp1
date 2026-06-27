#ifndef AUTENTICACAOVIEW_HPP
#define AUTENTICACAOVIEW_HPP

#include <modulos/autenticacao/IAutenticacaoView.hpp>
#include <modulos/autenticacao/AutenticacaoService.hpp>
#include <modulos/pessoa/IPessoaService.hpp>
#include <core/Panel.hpp>

/**
 * @brief Implementa a interface CLI para autenticação (login/logout).
 */
class AutenticacaoView : public IAutenticacaoView
{
private:
    IAutenticacaoService *service;
    IPessoaService *pessoaService;
    bool querSair = false;

    void interfaceLogin();
    void interfaceLogout();
    void interfacePrimeiroAcesso();

public:
    /**
     * @brief Constrói o módulo de autenticação e inicializa dependências.
     */
    AutenticacaoView();

    /**
     * @brief Libera recursos alocados.
     */
    ~AutenticacaoView();

    /**
     * @brief Exibe a tela de entrada (Login / Primeiro Acesso / Saída).
     * @return true se o usuário efetuou login com sucesso.
     */
    bool login() override;

    /**
     * @brief Exibe o fluxo de logout via CLI.
     */
    bool logout() override;

    /**
     * @brief Indica se o usuário escolheu sair da aplicação na tela de entrada.
     */
    bool getQuerSair() override;
};

#endif // AUTENTICACAOVIEW_HPP
