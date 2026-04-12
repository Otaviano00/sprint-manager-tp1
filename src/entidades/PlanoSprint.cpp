#include "PlanoSprint.hpp"

/**
 *  Define o código da sprint.
 */
void PlanoSprint::setCodigo(const Codigo &codigo) {
    this->codigo = codigo;
}

/**
 *  Retorna o código da sprint.
 */
Codigo PlanoSprint::getCodigo() const {
    return codigo;
}

/**
 *  Define o nome da sprint.
 */
void PlanoSprint::setNome(const Nome &nome) {
    this->nome = nome;
}

/**
 * Retorna o nome da sprint.
 */
Nome PlanoSprint::getNome() const {
    return nome;
}

/**
 *  Define a data de início da sprint.
 */
void PlanoSprint::setDataInicio(const Data &dataInicio) {
    this->dataInicio = dataInicio;
}

/**
 *  Retorna a data de início da sprint.
 */
Data PlanoSprint::getDataInicio() const {
    return dataInicio;
}

/**
    Define a data de fim da sprint.
 */
void PlanoSprint::setDataFim(const Data &dataFim) {
    this->dataFim = dataFim;
}

/**
 *  Retorna a data de fim da sprint.
 */
Data PlanoSprint::getDataFim() const {
    return dataFim;
}