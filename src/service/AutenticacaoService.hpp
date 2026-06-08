#ifndef AUTENTICACAOSERVICE_HPP
#define AUTENTICACAOSERVICE_HPP

#include <service/IAutenticacaoService.hpp>

class AutenticacaoService : public IAutenticacaoService
{
private:
    static AutenticacaoService *instance;
    Pessoa *pessoa;

    AutenticacaoService() : pessoa(nullptr) {}

public:
    static IAutenticacaoService *getInstance()
    {
        if (instance == nullptr)
        {
            static AutenticacaoService staticInstance;
            instance = &staticInstance;
        }
        return instance;
    }

    bool autenticarLogin(std::string email, std::string senha) override;
    PapelEnum getPapel() override;
};

#endif // AUTENTICACAOSERVICE_HPP