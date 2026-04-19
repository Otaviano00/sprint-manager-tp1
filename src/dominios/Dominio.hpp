#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

/**
 * @brief Classe base abstrata para domínios com validação de valor.
 *
 * @tparam T Tipo do valor encapsulado pelo domínio.
 */
template <typename T>
class Dominio
{
protected:
    /**
     * @brief Valor armazenado no domínio.
     */
    T valor;

    /**
     * @brief Valida um valor candidato para o domínio.
     *
     * @param valor Valor a ser validado.
     * @return true se o valor for válido.
     * @return false se o valor for inválido.
     */
    virtual bool validar(T valor) = 0;

public:
    /**
     * @brief Retorna o valor atual do domínio.
     *
     * @return T Valor armazenado.
     */
    T getValor() const
    {
        return valor;
    }

    /**
     * @brief Define um novo valor no domínio após validação.
     *
     * @param valor Novo valor a ser atribuído.
     * @return true se o valor for válido e atribuído.
     * @return false se o valor for inválido.
     */
    bool setValor(T valor)
    {
        if (!validar(valor))
        {
            return false;
        }
        this->valor = valor;
        return true;
    }
};

#endif // DOMINIOS_HPP_INCLUDED
