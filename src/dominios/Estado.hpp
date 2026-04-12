#ifndef ESTADO_HPP_INCLUDED
#define ESTADO_HPP_INCLUDED

#include "Dominio.hpp"

enum EstadoEnum
{
    /** @brief Estado inicial, ainda não iniciado. */
    A_FAZER,
    /** @brief Estado de execução da atividade. */
    FAZENDO,
    /** @brief Estado finalizado da atividade. */
    FEITO
};

/**
 * @brief Domínio para validação do estado das Histórias de Usuário
 */
class Estado : public Dominio<string>
{
private:
    /**
     * @brief Verifica se a string é um estado válido
     *
     * @param valor Valor textual a ser validado.
     * @return true quando o valor representa um estado válido.
     * @return false quando o valor não representa um estado válido.
     */
    bool validar(string valor);
};

#endif // ESTADO_HPP_INCLUDED