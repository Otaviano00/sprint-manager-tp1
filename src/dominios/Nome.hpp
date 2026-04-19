#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED

#include <string>
#include "Dominio.hpp"

/**
 * @brief Domínio para validação de nomes.
 */
class Nome : public Dominio<std::string>
{
private:
    /**
     * @brief Valida o valor informado para o domínio Nome.
     *
     * @param valor Nome em texto.
     * @return true quando o nome é válido.
     * @return false quando o nome é inválido.
     */
    bool validar(std::string valor);
};

#endif // NOME_HPP_INCLUDED