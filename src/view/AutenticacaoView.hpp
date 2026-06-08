#ifndef AUTENTICACAOVIEW_HPP
#define AUTENTICACAOVIEW_HPP

#include <view/IAutenticacaoView.hpp>
#include <service/AutenticacaoService.hpp>
#include <panel/Panel.hpp>

class AutenticacaoView : public IAutenticacaoView
{
private:
    IAutenticacaoService *service;
    JustOptionsPanel *menuLocal;

    void interfaceLogin();
    void interfaceLogout();

public:
    AutenticacaoView();

    void executar() override;
};

#endif // AUTENTICACAOVIEW_HPP
