#ifndef PANEL_HPP
#define PANEL_HPP

#include <string>
#include <vector>
#include <memory>
#include <functional>

class Panel
{

private:
    bool hasTitle = false;
    bool hasAction = false;
    bool hasOptions = false;
    bool hasZeroOption = true;
    bool hasEnd = false;
    bool hasConfirmation = false;

    std::string title;
    std::string zeroOptionLabel;
    std::vector<Panel *> options;
    std::function<void()> action = nullptr;
    std::function<void()> zeroOptionAction = nullptr;
    Panel *parent = nullptr;

    void showOptions();
    int choseOption();
    Panel *step(bool clearScreen);

public:
    Panel() = default;

    virtual ~Panel() = default;

    void showPanel();
    void showPanel(bool clearScreen);

    void setAction(std::function<void()> callback)
    {
        this->action = callback;
    }

    void addOption(Panel *option)
    {
        if (!this->hasOptions)
        {
            this->hasOptions = true;
        }

        option->parent = this;
        this->options.push_back(option);
    }

    void setZeroOption(const std::string &label, std::function<void()> callback = nullptr)
    {
        this->hasZeroOption = true;
        this->zeroOptionLabel = label;
        this->zeroOptionAction = callback;
    }

    friend class PanelBuilder;
};

#endif // PANEL_HPP