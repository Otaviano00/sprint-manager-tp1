#ifndef IHISTORIAUSUARIOVIEW_HPP
#define IHISTORIAUSUARIOVIEW_HPP

class IHistoriaUsuarioView
{
public:
    virtual void executar() = 0;
    virtual ~IHistoriaUsuarioView() = default;
};

#endif // IHISTORIAUSUARIOVIEW_HPP