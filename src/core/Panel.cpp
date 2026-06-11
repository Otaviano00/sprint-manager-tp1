#ifndef PANEL_CPP
#define PANEL_CPP

#include <iostream>
#include <core/Panel.hpp>
#include <util/ViewUtils.hpp>
#include <vector>
#include <stdexcept>

#define SIZE_DEFAULT 50

using namespace std;

int Panel::choseOption()
{
    std::string optionText;
    std::getline(cin, optionText);

    if (optionText.empty())
    {
        throw invalid_argument("Entrada inválida. Digite um número.");
    }

    size_t parsedLen = 0;
    int option = 0;
    try
    {
        option = std::stoi(optionText, &parsedLen);
    }
    catch (const std::exception &)
    {
        throw invalid_argument("Entrada inválida. Digite um número.");
    }

    if (parsedLen != optionText.length())
    {
        throw invalid_argument("Entrada inválida. Digite apenas números.");
    }

    if (option == 0)
    {
        if (!hasZeroOption)
        {
            throw invalid_argument("Opção inválida");
        }

        if (this->zeroOptionAction == nullptr)
        {
            return -1;
        }

        return option;
    }

    if (option < 1 || option > (int)this->options.size())
    {
        throw invalid_argument("Opção inválida");
    }

    return option;
}

void Panel::showOptions()
{
    for (int i = 0; i < (int)this->options.size(); i++)
    {
        cout << "[" << (i + 1) << "] - " << this->options.at(i)->title << endl;
    }

    if (hasZeroOption)
    {
        cout << "[0] - " << zeroOptionLabel << endl;
    }

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
    this->showPanel(true);
}

void Panel::showPanel(bool clearScreen)
{

    while (true)
    {
        if (clearScreen)
            ViewUtils::clear();

        if (this->hasTitle)
            showTitle(this->title, SIZE_DEFAULT);

        if (this->hasAction && this->action != nullptr)
        {
            try
            {
                this->action();

                if (this->hasEnd)
                {
                    cout << endl;
                    ViewUtils::waitForEnter();
                    break;
                }
            }
            catch (const exception &e)
            {
                if (this->hasEnd)
                {
                    ViewUtils::showErrorAndWait(e.what(), "[Pressione Enter para tentar novamente]");
                    break;
                }
                continue;
            }
        }

        if (this->hasOptions && !this->options.empty())
        {
            showOptions();

            try
            {
                int option = choseOption();

                if (this->hasConfirmation)
                {
                    if (!ViewUtils::confirmAction())
                    {
                        continue;
                    }
                }

                if (option == -1)
                {
                    break;
                }

                if (option == 0)
                {
                    this->zeroOptionAction();
                    break;
                }

                if (option > 0)
                    this->options.at(option - 1)->showPanel();
            }
            catch (const exception &e)
            {
                if (this->hasEnd)
                {
                    cout << endl;
                    ViewUtils::waitForEnter("[Pressione Enter para voltar ao menu]");
                    break;
                }
                else
                {
                    ViewUtils::showErrorAndWait(e.what(), "[Pressione Enter para tentar novamente]");
                }
            }
        }
    }
}

#endif // PANEL_CPP