#ifndef PAPEL_HPP_INCLUDED
#define PAPEL_HPP_INCLUDED

#include <string>
#include "Dominio.hpp"

enum PapelEnum
{
    /** @brief Papel de desenvolvedor. */
    DESENVOLVEDOR,
    /** @brief Papel de mestre scrum. */
    MESTRE_SCRUM,
    /** @brief Papel de proprietário de produto. */
    PROPRIETARIO_DE_PRODUTO
};

/**
 * @brief Domínio para validação dos papeis dos usuários do sistema
 */
class Papel : public Dominio<std::string>
{
private:
    /**
     * @brief Verifica se a string é um papel válido
     *
     * @param valor Valor textual a ser validado.
     * @return true quando o valor representa um papel válido.
     * @return false quando o valor não representa um papel válido.
     */
    bool validar(std::string valor);
};

#endif // PAPEL_HPP_INCLUDED