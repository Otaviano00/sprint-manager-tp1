#ifndef EMAIL_HPP_INCLUDED
#define EMAIL_HPP_INCLUDED

#include "Dominio.hpp"

/**
 * @brief Domínio para validação de endereços de e-mail.
 */
class Email : public Dominio<std::string>
{
private:
    /**
     * @brief Valida o valor informado para o domínio Email.
     *
     * @param valor E-mail em texto.
     * @return true quando o e-mail é válido.
     * @return false quando o e-mail é inválido.
     */
    bool validar(string valor);
};

#endif // EMAIL_HPP_INCLUDED