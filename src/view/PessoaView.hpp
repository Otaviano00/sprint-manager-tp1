#ifndef PESSOAVIEW_HPP
#define PESSOAVIEW_HPP

#include <view/IPessoaView.hpp>
#include <service/IPessoaService.hpp>
#include <panel/Panel.hpp>

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
    PessoaView();

    void executar() override;
};

#endif // PESSOAVIEW_HPP
