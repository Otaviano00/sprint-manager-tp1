#ifndef DATE_UTILS_HPP_INCLUDED
#define DATE_UTILS_HPP_INCLUDED

#include <dominios/Mes.hpp>

/**
 * @brief Conjunto de utilitários para regras de calendário e validação de datas.
 */
class DateUtils
{
public:
    /**
     * @brief Verifica se um ano é bissexto.
     *
     * @param year Ano a ser avaliado.
     * @return true quando o ano é bissexto.
     * @return false quando o ano não é bissexto.
     */
    static bool isAnoBissexto(int year);

    /**
     * @brief Verifica se uma data é válida no calendário gregoriano.
     *
     * @param day Dia do mês.
     * @param month Mês do ano.
     * @param year Ano.
     * @return true quando a data é válida.
     * @return false quando a data é inválida.
     */
    static bool isValidDate(int day, int month, int year);
};

#endif // DATE_UTILS_HPP_INCLUDED