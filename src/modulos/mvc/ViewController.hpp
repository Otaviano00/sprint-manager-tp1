#ifndef VIEWCONTROLLER_HPP
#define VIEWCONTROLLER_HPP

#include <modulos/mvc/IViewController.hpp>
#include <modulos/historia_usuario/IHistoriaUsuarioView.hpp>
#include <modulos/autenticacao/IAutenticacaoView.hpp>
#include <modulos/pessoa/IPessoaView.hpp>
#include <modulos/projeto/IProjetoView.hpp>
#include <modulos/plano_sprint/IPlanoSprintView.hpp>

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