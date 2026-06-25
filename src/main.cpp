#include <iostream>
#include <modulos/mvc/IViewController.hpp>
#include <modulos/mvc/ViewController.hpp>
#include <modulos/pessoa/PessoaRepository.hpp>
#include <modulos/pessoa/Pessoa.hpp>

int main()
{
    IViewController *viewController = new ViewController();

    viewController->executar();

    delete viewController;

    return 0;
}