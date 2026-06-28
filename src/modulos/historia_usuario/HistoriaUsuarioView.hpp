#ifndef HISTORIAUSUARIOVIEW_HPP
#define HISTORIAUSUARIOVIEW_HPP

#include <modulos/historia_usuario/IHistoriaUsuarioView.hpp>
#include <modulos/historia_usuario/IHistoriaUsuarioService.hpp>
#include <core/Panel.hpp>

class HistoriaUsuarioView : public IHistoriaUsuarioView
{
private:
    IHistoriaUsuarioService *service;

    Panel *montarPainelCriar();
    Panel *montarPainelListar();
    Panel *montarPainelBuscar();
    Panel *montarPainelAtualizar();
    Panel *montarPainelExcluir();
    Panel *montarPainelAlterarEstado();
    Panel *montarPainelVincular();
    Panel *montarPainelDesvincular();
    Panel *montarPainelMover();

public:
    HistoriaUsuarioView();
    ~HistoriaUsuarioView();
    void executar() override;
};

#endif // HISTORIAUSUARIOVIEW_HPP
