#ifndef VIEWCONTROLLER_HPP
#define VIEWCONTROLLER_HPP

#include <view/IViewController.hpp>
#include <view/IHistoriaUsuarioView.hpp>
#include <view/IAutenticacaoView.hpp>
#include <view/IPessoaView.hpp>
#include <view/IProjetoView.hpp>
#include <view/IPlanoSprintView.hpp>

/**
 * @brief Controlador principal que orquestra a navegação entre módulos de view.
 */
class ViewController : public IViewController
{
private:
    IHistoriaUsuarioView *historiaView;
    IAutenticacaoView *autenticacaoView;
    IPessoaView *pessoaView;
    IProjetoView *projetoView;
    IPlanoSprintView *planoSprintView;

public:
    /**
     * @brief Constrói o controlador principal e instancia submódulos visuais.
     */
    ViewController();

    /**
     * @brief Libera recursos alocados pelo controlador principal.
     */
    ~ViewController();

    /**
     * @brief Exibe o menu principal e delega fluxo para submódulos.
     */
    void executar() override;
};

#endif // VIEWCONTROLLER_HPP