#ifndef AUTENTICACAOVIEW_HPP
#define AUTENTICACAOVIEW_HPP

#include <view/IAutenticacaoView.hpp>
#include <service/AutenticacaoService.hpp>
#include <panel/Panel.hpp>

/**
 * @brief Implementa a interface CLI para autenticação (login/logout).
 */
class AutenticacaoView : public IAutenticacaoView
{
private:
    IAutenticacaoService *service;
    JustOptionsPanel *menuLocal;

    void interfaceLogin();
    void interfaceLogout();

public:
    /**
     * @brief Constrói o módulo de autenticação e inicializa dependências.
     */
    AutenticacaoView();

    /**
     * @brief Exibe o menu de autenticação e executa ações selecionadas.
     */
    void executar() override;
};

#endif // AUTENTICACAOVIEW_HPP
