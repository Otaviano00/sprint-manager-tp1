#ifndef TEMPO_HPP_INCLUDED
#define TEMPO_HPP_INCLUDED

#include <dominios/Dominio.hpp>

/**
 * @brief Domínio para validação de duração em dias.
 */
class Tempo : public Dominio<int>
{
private:
    /**
     * @brief Valida o valor informado para o domínio Tempo.
     *
     * @param valor Quantidade de dias.
     * @return true quando o valor é válido.
     * @return false quando o valor é inválido.
     */
    bool validar(int valor);
};

#endif // TEMPO_HPP_INCLUDED