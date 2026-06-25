#ifndef PANEL_BUILDER_HPP
#define PANEL_BUILDER_HPP

#include <core/Panel.hpp>

class PanelBuilder
{
private:
    Panel *panel = nullptr;
    static PanelBuilder *instance;

    PanelBuilder() : panel(new Panel()) {}

public:
    PanelBuilder *withTitle(const std::string &title);
    PanelBuilder *withInitialCleanScreen(bool cleanScreen = true);
    PanelBuilder *withAction(std::function<void()> action);
    PanelBuilder *withOptions(bool hasOptions, std::vector<Panel *> options = {});
    PanelBuilder *withZeroAction(bool hasZeroOption, const std::string &label = "Retornar", std::function<void()> action = nullptr, bool hasZeroConfirmation = false);
    PanelBuilder *withEnd(bool hasEnd);
    PanelBuilder *withConfirmation(bool hasConfirmation = true);
    PanelBuilder *withExitCondition(std::function<bool()> condition);

    static PanelBuilder *builder()
    {
        if (instance == nullptr)
        {
            instance = new PanelBuilder();
        }

        return instance;
    }

    Panel *build();
};

#endif // PANEL_BUILDER_HPP