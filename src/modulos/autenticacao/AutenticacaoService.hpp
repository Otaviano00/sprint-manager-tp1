#ifndef AUTENTICACAOSERVICE_HPP
#define AUTENTICACAOSERVICE_HPP

#include <modulos/autenticacao/IAutenticacaoService.hpp>

/**
 * @brief Implementação de autenticação e gerenciamento de sessão da aplicação.
 */
class AutenticacaoService : public IAutenticacaoService
{
private:
    static AutenticacaoService *instance;
    Pessoa *pessoa;

    AutenticacaoService() : pessoa(nullptr) {}

public:
    /**
     * @brief Retorna a instância singleton do serviço de autenticação.
     * @return Ponteiro para a interface de autenticação.
     */
    static IAutenticacaoService *getInstance()
    {
        if (instance == nullptr)
        {
            static AutenticacaoService staticInstance;
            instance = &staticInstance;
        }
        return instance;
    }

    /**
     * @brief Valida credenciais e atualiza a sessão do usuário.
     * @param email Email informado no login.
     * @param senha Senha informada no login.
     * @return true quando as credenciais forem válidas.
     */
    bool autenticarLogin(std::string email, std::string senha) override;

    /**
     * @brief Obtém o papel do usuário autenticado na sessão atual.
     * @return PapelEnum do usuário logado.
     */
    PapelEnum getPapel() override;
};

#endif // AUTENTICACAOSERVICE_HPP