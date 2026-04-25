#ifndef PROJETO_HPP_INCLUDED
#define PROJETO_HPP_INCLUDED

#include <dominios/Codigo.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Data.hpp>

/**
 * @brief Classe que representa um projeto.
 *
 * Armazena as informações básicas de um projeto de desenvolvimento.
 */
class Projeto
{
private:
    Codigo codigo;   /**< Código identificador do projeto. */
    Nome nome;       /**< Nome do projeto. */
    Data dataInicio; /**< Data de início do projeto. */
    Data dataFim;    /**< Data de fim do projeto. */

public:
    /**
     * @brief Define o código do projeto.
     *
     * @param codigo Instância do domínio Codigo contendo o código validado.
     */
    void setCodigo(const Codigo &codigo);

    /**
     * @brief Retorna o código do projeto.
     *
     * @return Instância do domínio Codigo.
     */
    Codigo getCodigo() const;

    /**
     * @brief Define o nome do projeto.
     *
     * @param nome Instância do domínio Nome contendo o nome validado.
     */
    void setNome(const Nome &nome);

    /**
     * @brief Retorna o nome do projeto.
     *
     * @return Instância do domínio Nome.
     */
    Nome getNome() const;

    /**
     * @brief Define a data de início do projeto.
     *
     * @param dataInicio Instância do domínio Data contendo a data de início validada.
     */
    void setDataInicio(const Data &dataInicio);

    /**
     * @brief Retorna a data de início do projeto.
     *
     * @return Instância do domínio Data correspondente à data de início.
     */
    Data getDataInicio() const;

    /**
     * @brief Define a data de fim do projeto.
     *
     * @param dataFim Instância do domínio Data contendo a data de fim validada.
     */
    void setDataFim(const Data &dataFim);

    /**
     * @brief Retorna a data de fim do projeto.
     *
     * @return Instância do domínio Data correspondente à data de fim.
     */
    Data getDataFim() const;
};

#endif