#ifndef PLANOSPRINT_HPP_INCLUDED
#define PLANOSPRINT_HPP_INCLUDED

#include <dominios/Codigo.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Data.hpp>

/**
 * @brief Classe que representa um plano de sprint.
 *
 * Armazena as informações básicas de uma sprint dentro de um projeto.
 */
class PlanoSprint
{
private:
  Codigo codigo;   /**< Código identificador da sprint. */
  Nome nome;       /**< Nome da sprint. */
  Data dataInicio; /**< Data de início da sprint. */
  Data dataFim;    /**< Data de fim da sprint. */

public:
  /**
   * @brief Define o código da sprint.
   *
   * @param codigo Instância do domínio Codigo contendo o código validado.
   */
  void setCodigo(const Codigo &codigo);

  /**
   * @brief Retorna o código da sprint.
   *
   * @return Instância do domínio Codigo.
   */
  Codigo getCodigo() const;

  /**
   * @brief Define o nome da sprint.
   *
   * @param nome Instância do domínio Nome contendo o nome validado.
   */
  void setNome(const Nome &nome);

  /**
   * @brief Retorna o nome da sprint.
   *
   * @return Instância do domínio Nome.
   */
  Nome getNome() const;

  /**
   * @brief Define a data de início da sprint.
   *
   * @param dataInicio Instância do domínio Data contendo a data de início validada.
   */
  void setDataInicio(const Data &dataInicio);

  /**
   * @brief Retorna a data de início da sprint.
   *
   * @return Instância do domínio Data correspondente à data de início.
   */
  Data getDataInicio() const;

  /**
   * @brief Define a data de fim da sprint.
   *
   * @param dataFim Instância do domínio Data contendo a data de fim validada.
   */
  void setDataFim(const Data &dataFim);

  /**
   * @brief Retorna a data de fim da sprint.
   *
   * @return Instância do domínio Data correspondente à data de fim.
   */
  Data getDataFim() const;
};

#endif