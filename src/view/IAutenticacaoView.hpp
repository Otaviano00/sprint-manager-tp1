#ifndef IAUTENTICACAOVIEW_HPP
#define IAUTENTICACAOVIEW_HPP

class IAutenticacaoView
{
public:
    virtual void executar() = 0;
    virtual ~IAutenticacaoView() = default;
};

#endif // IAUTENTICACAOVIEW_HPP