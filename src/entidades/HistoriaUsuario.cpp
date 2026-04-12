#include "HistoriaUsuario.hpp"

// =======================================================
// SETTERS
// Cada setter recebe um objeto dominio ja validado.
// A responsabilidade de validar o formato/valor e do
// dominio se o valor fosse invalido, uma excecao ja
// teria sido lancada antes de chegar aqui.
// =======================================================

// Atribui o codigo (chave primaria) da historia
void HistoriaUsuario::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}

// Atribui o titulo da historia
void HistoriaUsuario::setTitulo(const Texto& titulo) {
    this->titulo = titulo;
}

// Atribui o papel — quem deseja a funcionalidade
void HistoriaUsuario::setPapel(const Texto& papel) {
    this->papel = papel;
}

// Atribui a acao — o que se deseja realizar
void HistoriaUsuario::setAcao(const Texto& acao) {
    this->acao = acao;
}

// Atribui o valor — beneficio esperado da historia
void HistoriaUsuario::setValor(const Texto& valor) {
    this->valor = valor;
}

// Atribui a estimativa de esforco em dias (1 a 365)
void HistoriaUsuario::setEstimativa(const Tempo& estimativa) {
    this->estimativa = estimativa;
}

// Atribui a prioridade da historia (ALTA, MEDIA ou BAIXA)
void HistoriaUsuario::setPrioridade(const Prioridade& prioridade) {
    this->prioridade = prioridade;
}

// Atribui o estado atual da historia (A_FAZER, FAZENDO ou FEITO)
void HistoriaUsuario::setEstado(const Estado& estado) {
    this->estado = estado;
}

// =======================================================
// GETTERS
// Cada getter retorna uma copia do atributo correspondente.
// Sao marcados como const pois nao alteram o estado do objeto.
// =======================================================

// Retorna o codigo da historia
Codigo HistoriaUsuario::getCodigo() const {
    return codigo;
}

// Retorna o titulo da historia
Texto HistoriaUsuario::getTitulo() const {
    return titulo;
}

// Retorna o papel da historia
Texto HistoriaUsuario::getPapel() const {
    return papel;
}

// Retorna a acao da historia
Texto HistoriaUsuario::getAcao() const {
    return acao;
}

// Retorna o valor da historia
Texto HistoriaUsuario::getValor() const {
    return valor;
}

// Retorna a estimativa de esforco
Tempo HistoriaUsuario::getEstimativa() const {
    return estimativa;
}

// Retorna a prioridade da historia
Prioridade HistoriaUsuario::getPrioridade() const {
    return prioridade;
}

// Retorna o estado atual da historia
Estado HistoriaUsuario::getEstado() const {
    return estado;
}