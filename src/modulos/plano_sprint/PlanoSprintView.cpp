#include <modulos/plano_sprint/PlanoSprintView.hpp>
#include <modulos/plano_sprint/PlanoSprintService.hpp>
#include <core/PanelBuilder.hpp>
#include <iostream>

PlanoSprintView::PlanoSprintView()
{
    service = new PlanoSprintService();
}

void PlanoSprintView::executar()
{
 
    Panel *panelCriar = PanelBuilder::builder()
        ->withTitle("Criar Plano de Sprint")
        ->withAction([this]() {
            PlanoSprint ps;
            service->criar(ps);
            std::cout << "Plano criado com sucesso!" << std::endl;
        })
        ->withZeroAction(false)
        ->withEnd(true)
        ->build();

    
    Panel *panelListar = PanelBuilder::builder()
        ->withTitle("Listar Planos de Sprint")
        ->withAction([this]() {
            auto lista = service->listar();
            for (auto &ps : lista)
                std::cout << ps.getId() << std::endl; 
        })
        ->withZeroAction(false)
        ->withEnd(true)
        ->build();

    
    Panel *panelAtualizar = PanelBuilder::builder()
        ->withTitle("Atualizar Plano de Sprint")
        ->withAction([this]() {
            int id;
            std::cout << "ID do plano: ";
            std::cin >> id; std::cin.ignore();
            PlanoSprint ps = service->listarPorId(id);
            service->atualizar(ps);
            std::cout << "Plano atualizado!" << std::endl;
        })
        ->withZeroAction(false)
        ->withEnd(true)
        ->build();

    Panel *panelExcluir = PanelBuilder::builder()
        ->withTitle("Excluir Plano de Sprint")
        ->withAction([this]() {
            int id;
            std::cout << "ID do plano a excluir: ";
            std::cin >> id; std::cin.ignore();
            service->excluir(id);
            std::cout << "Plano excluído!" << std::endl;
        })
        ->withConfirmation(true)
        ->withZeroAction(false)
        ->withEnd(true)
        ->build();

    Panel *menuPrincipal = PanelBuilder::builder()
        ->withTitle("Planos de Sprint")
        ->withOptions(true, {panelCriar, panelListar, panelAtualizar, panelExcluir})
        ->withZeroAction(true) 
        ->build();

    menuPrincipal->showPanel();

    delete panelCriar;
    delete panelListar;
    delete panelAtualizar;
    delete panelExcluir;
    delete menuPrincipal;
}