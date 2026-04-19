#ifndef PRIORIDADE_HPP_INCLUDED
#define PRIORIDADE_HPP_INCLUDED

#include <string>
#include "Dominio.hpp"

enum PrioridadeEnum
{
    /** @brief Nível alto. */
    ALTA = 3,
    /** @brief Nível médio. */
    MEDIA = 2,
    /** @brief Nível baixo. */
    BAIXA = 1
};

/**
 * @brief Domínio para validação da prioridade das Histórias de Usuário
 */
class Prioridade : public Dominio<std::string>
{
private:
    /**
     * @brief Verifica se a string é uma prioridade válida
     *
     * @param valor Valor textual a ser validado.
     * @return true quando o valor representa uma prioridade válida.
     * @return false quando o valor não representa uma prioridade válida.
     */
    bool validar(std::string valor);
};

#endif // PRIORIDADE_HPP_INCLUDED