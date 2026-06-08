#ifndef IVIEWCONTROLLER_HPP
#define IVIEWCONTROLLER_HPP

class IViewController
{
public:
    virtual void executar() = 0;
    virtual ~IViewController() = default;
};

#endif // IVIEWCONTROLLER_HPP