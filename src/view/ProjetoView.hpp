#ifndef PROJETOVIEW_HPP
#define PROJETOVIEW_HPP

#include <view/IProjetoView.hpp>
#include <service/IProjetoService.hpp>
#include <panel/Panel.hpp>

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
    ProjetoView();

    void executar() override;
};

#endif // PROJETOVIEW_HPP
