#ifndef IPESSOAVIEW_HPP
#define IPESSOAVIEW_HPP

class IPessoaView
{
public:
    virtual void executar() = 0;
    virtual ~IPessoaView() = default;
};

#endif // IPESSOAVIEW_HPP
