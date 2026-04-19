#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED

#include <string>
#include "Dominio.hpp"

/**
 * @brief Domínio para validação de senhas.
 */
class Senha : public Dominio<std::string>
{
private:
    /**
     * @brief Valida o valor informado para o domínio Senha.
     *
     * @param valor Senha em texto.
     * @return true quando a senha é válida.
     * @return false quando a senha é inválida.
     */
    bool validar(std::string valor);
};

#endif // SENHA_HPP_INCLUDED