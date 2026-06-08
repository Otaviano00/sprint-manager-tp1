#ifndef HISTORIAUSUARIOVIEW_HPP
#define HISTORIAUSUARIOVIEW_HPP

#include <view/IHistoriaUsuarioView.hpp>
#include <service/IHistoriaUsuarioService.hpp>
#include <panel/Panel.hpp>

class HistoriaUsuarioView : public IHistoriaUsuarioView
{
private:
    IHistoriaUsuarioService *service;
    JustOptionsPanel *menuLocal; // Árvore local de opções deste módulo

    void interfaceCriarHistoria();
    void interfaceListarHistorias();

public:
    HistoriaUsuarioView();

    void executar() override;
};

#endif // HISTORIAUSUARIOVIEW_HPP