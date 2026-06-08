#ifndef HISTORIAUSUARIOVIEW_HPP
#define HISTORIAUSUARIOVIEW_HPP

#include <view/IHistoriaUsuarioView.hpp>
#include <service/IHistoriaUsuarioService.hpp>
#include <panel/Panel.hpp>

/**
 * @brief Implementa a interface CLI para operações de história de usuário.
 */
class HistoriaUsuarioView : public IHistoriaUsuarioView
{
private:
    IHistoriaUsuarioService *service;
    JustOptionsPanel *menuLocal; // Árvore local de opções deste módulo

    void interfaceCriarHistoria();
    void interfaceListarHistorias();

public:
    /**
     * @brief Constrói o módulo de histórias de usuário e inicializa dependências.
     */
    HistoriaUsuarioView();

    /**
     * @brief Exibe o menu de histórias de usuário e executa ações selecionadas.
     */
    void executar() override;
};

#endif // HISTORIAUSUARIOVIEW_HPP