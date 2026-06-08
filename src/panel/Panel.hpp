#ifndef PANEL_BASE
#define PANEL_BASE

#include <string>
#include <vector>
#include <memory>
#include <functional>

class Panel
{
protected:
    bool hasTitle;
    bool hasContent;
    bool hasOptions;
    std::string title;
    std::vector<Panel *> panels;

    std::function<void()> action = nullptr;
    void showOptions();
    bool choseOption();

public:
    Panel(std::string title = "", bool hasContent = false, bool hasOptions = true);
    virtual ~Panel() = default;

    void setAction(std::function<void()> callback)
    {
        this->action = callback;
    }
    void addOption(Panel *option)
    {
        this->panels.push_back(option);
    }
    void showPanel();
};

class ActionPanel : public Panel
{
public:
    ActionPanel(std::string title, std::function<void()> callback)
        : Panel(title, true, false)
    {
        this->setAction(callback);
    }
};

class JustOptionsPanel : public Panel
{
public:
    JustOptionsPanel()
        : Panel("", false, true)
    {
    }
};

#endif // PANEL_BASE