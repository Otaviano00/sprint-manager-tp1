#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include "Dominio.hpp"

/**
 * @brief Domínio para validação de datas no formato dd/mm/aaaa.
 */
class Data : public Dominio<std::string>
{
private:
    /**
     * @brief Valida o valor informado para o domínio Data.
     *
     * @param valor Data em texto.
     * @return true quando a data é válida.
     * @return false quando a data é inválida.
     */
    bool validar(string valor);
};

#endif // DATA_HPP_INCLUDED