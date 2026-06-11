#ifndef HISTORIAUSUARIOVIEW_HPP
#define HISTORIAUSUARIOVIEW_HPP

#include <modulos/historia_usuario/IHistoriaUsuarioView.hpp>
#include <modulos/historia_usuario/IHistoriaUsuarioService.hpp>
#include <core/Panel.hpp>

/**
 * @brief Implementa a interface CLI para operações de história de usuário.
 */
class HistoriaUsuarioView : public IHistoriaUsuarioView
{
private:
    IHistoriaUsuarioService *service;

public:
    /**
     * @brief Constrói o módulo de histórias de usuário e inicializa dependências.
     */
    HistoriaUsuarioView() = default;

    /**
     * @brief Exibe o menu de histórias de usuário e executa ações selecionadas.
     */
    void executar() override;
};

#endif // HISTORIAUSUARIOVIEW_HPP