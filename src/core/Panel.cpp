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

Panel *Panel::step()
{
    if (this->exitCondition && this->exitCondition())
        return nullptr;

    if (this->cleanScreen)
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
                if (this->hasConfirmation)
                {
                    if (ViewUtils::confirmAction("Deseja continuar? (S/n)"))
                    {
                        return this;
                    }

                    return nullptr;
                }

                ViewUtils::waitForEnter();

                return nullptr;
            }
        }
        catch (const exception &e)
        {
            ViewUtils::showError(e.what());

            if (ViewUtils::confirmAction("Deseja tentar novamente? (S/n)"))
            {
                return this;
            }

            return nullptr;
        }
    }

    if (this->hasOptions && !this->options.empty())
    {
        showOptions();

        try
        {
            int option = choseOption();

            if (this->hasConfirmation && !ViewUtils::confirmAction())
            {
                return this;
            }

            if (option == -1)
            {
                return nullptr;
            }

            if (option == 0)
            {
                if (this->hasZeroConfirmation && !ViewUtils::confirmAction())
                {
                    return this;
                }
                this->zeroOptionAction();
                return nullptr;
            }

            if (option > 0)
            {
                return this->options.at(option - 1);
            }
        }
        catch (const exception &e)
        {
            ViewUtils::showError(e.what());

            if (ViewUtils::confirmAction("Deseja tentar novamente? (S/n)"))
            {
                return this;
            }

            return nullptr;
        }
    }

    return nullptr;
}

void Panel::showPanel()
{
    Panel *current = this;

    while (current != nullptr)
    {
        Panel *next = current->step();

        if (next == nullptr)
        {
            if (current->parent == nullptr)
                break;
            current = current->parent;
        }
        else
        {
            current = next;
        }
    }
}

void Panel::addOption(Panel *option)
{
    if (!this->hasOptions)
    {
        this->hasOptions = true;
    }

    option->parent = this;
    this->options.push_back(option);
}

#endif // PANEL_CPP