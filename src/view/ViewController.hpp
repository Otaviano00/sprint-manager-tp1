#ifndef VIEWCONTROLLER_HPP
#define VIEWCONTROLLER_HPP

#include <view/IViewController.hpp>
#include <view/IHistoriaUsuarioView.hpp>
#include <view/IAutenticacaoView.hpp>
#include <view/IPessoaView.hpp>
#include <view/IProjetoView.hpp>
#include <view/IPlanoSprintView.hpp>

class ViewController : public IViewController
{
private:
    IHistoriaUsuarioView *historiaView;
    IAutenticacaoView *autenticacaoView;
    IPessoaView *pessoaView;
    IProjetoView *projetoView;
    IPlanoSprintView *planoSprintView;

public:
    ViewController();
    ~ViewController();

    void executar() override;
};

#endif // VIEWCONTROLLER_HPP