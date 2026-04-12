#ifndef PLANOSPRINT_HPP_INCLUDED
#define PLANOSPRINT_HPP_INCLUDED

#include "../dominios/dominios.hpp"

/**
 * Classe que representa um plano de sprint.
 *
 * Armazena informações básicas de uma sprint dentro de um projeto.
 */
class PlanoSprint {
private:
    Codigo codigo; // Código da sprint
    Nome nome;     // Nome da sprint
    Data dataInicio; // Data de início
    Data dataFim;    // Data de fim

public:

    /**
     *  Define o código da sprint.
     */
    void setCodigo(const Codigo &);

    /**
     *  Retorna o código da sprint.
     */
    Codigo getCodigo() const;

    /**
     *  Define o nome da sprint.
     */
    void setNome(const Nome &);

    /**
     * Retorna o nome da sprint.
     */
    Nome getNome() const;

    /**
      Define a data de início da sprint.
     */
    void setDataInicio(const Data &);

    /**
      Retorna a data de início da sprint.
     */
    Data getDataInicio() const;

    /**
      Define a data de fim da sprint.
     */
    void setDataFim(const Data &);

    /**
     Retorna a data de fim da sprint.
     */
    Data getDataFim() const;
};

#endif