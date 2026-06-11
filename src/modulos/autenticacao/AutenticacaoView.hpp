#ifndef AUTENTICACAOVIEW_HPP
#define AUTENTICACAOVIEW_HPP

#include <modulos/autenticacao/IAutenticacaoView.hpp>
#include <modulos/autenticacao/AutenticacaoService.hpp>
#include <core/Panel.hpp>

/**
 * @brief Implementa a interface CLI para autenticação (login/logout).
 */
class AutenticacaoView : public IAutenticacaoView
{
private:
    IAutenticacaoService *service;

    void interfaceLogin();
    void interfaceLogout();

public:
    /**
     * @brief Constrói o módulo de autenticação e inicializa dependências.
     */
    AutenticacaoView();

    /**
     * @brief Exibe o fluxo de login via CLI.
     *
     */
    bool login() override;

    /**
     * @brief Exibe o fluxo de logout via CLI.
     *
     */
    bool logout() override;
};

#endif // AUTENTICACAOVIEW_HPP
