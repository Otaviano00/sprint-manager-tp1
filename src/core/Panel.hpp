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
    bool cleanScreen = true;
    bool hasEnd = false;
    bool hasConfirmation = false;
    bool hasZeroConfirmation = false;

    std::string title;
    std::string zeroOptionLabel;
    std::vector<Panel *> options;
    std::function<void()> action = nullptr;
    std::function<void()> zeroOptionAction = nullptr;
    std::function<bool()> exitCondition = nullptr;
    Panel *parent = nullptr;

    void showOptions();
    int choseOption();
    Panel *step();

public:
    Panel() = default;

    virtual ~Panel() = default;

    void showPanel();
    void addOption(Panel *option);

    friend class PanelBuilder;
};

#endif // PANEL_HPP