#include <core/PanelBuilder.hpp>
#include <core/Panel.hpp>

PanelBuilder *PanelBuilder::instance = nullptr;

PanelBuilder *PanelBuilder::withTitle(const std::string &title)
{
    this->panel->title = title;
    this->panel->hasTitle = true;
    return this;
}

PanelBuilder *PanelBuilder::withInitialCleanScreen(bool cleanScreen)
{
    this->panel->cleanScreen = cleanScreen;
    return this;
}

PanelBuilder *PanelBuilder::withAction(std::function<void()> action)
{
    this->panel->hasAction = action != nullptr;
    this->panel->action = action;
    return this;
}

PanelBuilder *PanelBuilder::withOptions(bool hasOptions, std::vector<Panel *> options)
{
    this->panel->hasOptions = hasOptions;
    this->panel->options = options;
    return this;
}

PanelBuilder *PanelBuilder::withZeroAction(bool hasZeroOption, const std::string &label, std::function<void()> action, bool hasZeroConfirmation)
{
    this->panel->hasZeroOption = hasZeroOption;
    this->panel->zeroOptionLabel = label;
    this->panel->zeroOptionAction = action;
    this->panel->hasZeroConfirmation = hasZeroConfirmation;
    return this;
}

PanelBuilder *PanelBuilder::withEnd(bool hasEnd)
{
    this->panel->hasEnd = hasEnd;
    return this;
}

PanelBuilder *PanelBuilder::withConfirmation(bool hasConfirmation)
{
    this->panel->hasConfirmation = hasConfirmation;
    return this;
}

PanelBuilder *PanelBuilder::withExitCondition(std::function<bool()> condition)
{
    this->panel->exitCondition = condition;
    return this;
}

Panel *PanelBuilder::build()
{
    Panel *builtPanel = this->panel;
    this->panel = new Panel();
    return builtPanel;
}
