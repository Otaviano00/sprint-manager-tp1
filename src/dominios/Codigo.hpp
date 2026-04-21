#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED

#include <string>
#include <dominios/Dominio.hpp>

/**
 * @brief Domínio responsável por validar códigos no formato de 2 letras maiúsculas e 3 dígitos.
 */
class Codigo : public Dominio<std::string>
{
private:
    /**
     * @brief Valida o valor informado para o domínio Codigo.
     *
     * @param valor Texto a ser validado.
     * @return true quando o formato é válido.
     * @return false quando o formato é inválido.
     */
    bool validar(std::string valor);
};

#endif // CODIGO_HPP_INCLUDED