#ifndef IAUTENTICACAOSINGLETON_HPP
#define IAUTENTICACAOSINGLETON_HPP

#include <string>
#include <stdexcept>
#include <util/ServicoEnum.hpp>
#include <dominios/Papel.hpp>
#include <modulos/pessoa/Pessoa.hpp>

/**
 * @brief Contrato de serviços de autenticação e sessão do sistema.
 */
class IAutenticacaoService
{
public:
    /**
     * @brief Valida credenciais de acesso e inicializa a sessão corrente.
     * @param email Email informado no login.
     * @param senha Senha informada no login.
     * @return true quando a autenticação for bem-sucedida.
     */
    virtual bool autenticarLogin(std::string email, std::string senha) = 0;

    /**
     * @brief Retorna o papel do usuário autenticado na sessão atual.
     * @return PapelEnum do usuário logado.
     */
    virtual PapelEnum getPapel() = 0;

    /**
     * @brief Destrutor virtual da interface de autenticação.
     */
    virtual ~IAutenticacaoService() = default;
};

#endif // IAUTENTICACAOSINGLETON_HPP
