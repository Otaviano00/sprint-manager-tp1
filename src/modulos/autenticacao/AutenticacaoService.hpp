#ifndef AUTENTICACAOSERVICE_HPP
#define AUTENTICACAOSERVICE_HPP

#include <modulos/autenticacao/IAutenticacaoService.hpp>
#include <modulos/pessoa/PessoaRepository.hpp>

/**
 * @brief Implementação de autenticação e gerenciamento de sessão da aplicação.
 */
class AutenticacaoService : public IAutenticacaoService
{
private:
    PessoaRepository *pessoaRepository;
    Pessoa *pessoa;

    AutenticacaoService() : pessoa(nullptr), pessoaRepository(new PessoaRepository())
    {
    }

public:
    /**
     * @brief Retorna a instância singleton do serviço de autenticação.
     * @return Ponteiro para a interface de autenticação.
     */
    static IAutenticacaoService *getInstance()
    {
        static AutenticacaoService staticInstance;
        return &staticInstance;
    }

    /**
     * @brief Valida credenciais e atualiza a sessão do usuário.
     * @param email Email informado no login.
     * @param senha Senha informada no login.
     * @return true quando as credenciais forem válidas.
     */
    bool login(Email email, Senha senha) override;

    /**
     * @brief Encerra a sessão atual.
     */
    void logout() override;

    /**
     * @brief Verifica se há um usuário autenticado na sessão atual.
     * @return true se um usuário estiver logado.
     */
    bool isLoggedIn() override;

    /**
     * @brief Obtém o papel do usuário autenticado na sessão atual.
     * @return PapelEnum do usuário logado.
     */
    PapelEnum getPapel() override;
};

#endif // AUTENTICACAOSERVICE_HPP