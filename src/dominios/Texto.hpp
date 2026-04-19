#ifndef TEXTO_HPP_INCLUDED
#define TEXTO_HPP_INCLUDED

#include <string>
#include "Dominio.hpp"

/**
 * @brief Domínio para validação de textos curtos.
 */
class Texto : public Dominio<std::string>
{
private:
    /**
     * @brief Valida o valor informado para o domínio Texto.
     *
     * @param valor Texto a ser validado.
     * @return true quando o texto é válido.
     * @return false quando o texto é inválido.
     */
    bool validar(std::string valor);
};

#endif // TEXTO_HPP_INCLUDED