#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED

#include <string>
#include <dominios/Dominio.hpp>

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
     * @throw invalid_argument Quando o nome é inválido.
     */
    void validar(std::string valor);
};

#endif // NOME_HPP_INCLUDED