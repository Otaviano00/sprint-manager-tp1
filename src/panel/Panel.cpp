#ifndef PANEL_CPP
#define PANEL_CPP

#include <iostream>
#include <panel/Panel.hpp>
#include <vector>
#include <stdexcept>

#define SIZE_DEFAULT 20

#ifndef _WIN32
#define CLEAR "clear"
#else
#define CLEAR "cls"
#endif

using namespace std;

void clear()
{
    system(CLEAR);
}

Panel::Panel(string title, bool hasContent, bool hasOptions)
    : hasTitle(!title.empty()), hasContent(hasContent), hasOptions(hasOptions), title(title)
{
}

bool Panel::choseOption()
{
    int option;

    if (!(cin >> option))
    {
        cin.clear();             // Limpa as flags de erro do cin ANTES de ignorar
        cin.ignore(10000, '\n'); // Descarta a sequência de letras inválida digitada
        throw invalid_argument("Entrada inválida. Digite um número.");
    }

    cin.ignore(10000, '\n');

    if (option == 0)
    {
        return false;
    }

    if (option < 1 || option > (int)this->panels.size())
    {
        throw invalid_argument("Opção inválida");
    }

    clear();
    this->panels.at(option - 1)->showPanel();
    return true;
}

void Panel::showOptions()
{
    for (int i = 0; i < (int)this->panels.size(); i++)
    {
        cout << "[" << (i + 1) << "] - " << this->panels.at(i)->title << endl;
    }

    cout << "[0] - Retornar" << endl;

    cout << endl;
}

void showTitle(std::string title, int length)
{
    // Lógica de centralização do título
    int currentLen = (int)title.size();
    int sides = (length > currentLen) ? (length - currentLen) / 2 : 0;

    for (int i = 0; i < sides; i++)
        cout << "=";

    cout << " " << title << " ";

    for (int i = 0; i < sides; i++)
        cout << "=";

    cout << endl;
}

void Panel::showPanel()
{

    while (true)
    {
        clear();

        if (this->hasTitle)
            showTitle(this->title, SIZE_DEFAULT);

        if (this->hasContent && this->action != nullptr)
            this->action();

        if (this->hasOptions && !this->panels.empty())
        {
            showOptions();

            try
            {
                if (!choseOption())
                {
                    break;
                }
            }
            catch (const exception &e)
            {
                cout << "Erro: " << e.what() << endl;
                cout << "[Pressione Enter para tentar novamente]" << endl;
                cin.get();
            }
        }
        else
        {
            cout << endl
                 << "[Pressione Enter para voltar]" << endl;
            cin.get();
            break;
        }
    }
}

#endif // PANEL_CPP