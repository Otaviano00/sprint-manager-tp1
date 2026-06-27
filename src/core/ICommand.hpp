#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP

/**
 * @brief Interface comum para objetos Command.
 */
class ICommand
{
public:
    virtual void executar() = 0;
    virtual ~ICommand() = default;
};

#endif // ICOMMAND_HPP