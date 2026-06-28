#include <modulos/historia_usuario/HistoriaDeUsuario.hpp>

// Setters
void HistoriaDeUsuario::setCodigo(const Codigo &codigo)
{
    this->codigo = codigo;
}
void HistoriaDeUsuario::setTitulo(const Texto &titulo)
{
    this->titulo = titulo;
}
void HistoriaDeUsuario::setPapel(const Texto &papel)
{
    this->papel = papel;
}
void HistoriaDeUsuario::setAcao(const Texto &acao)
{
    this->acao = acao;
}
void HistoriaDeUsuario::setValor(const Texto &valor)
{
    this->valor = valor;
}
void HistoriaDeUsuario::setEstimativa(const Tempo &estimativa)
{
    this->estimativa = estimativa;
}
void HistoriaDeUsuario::setPrioridade(const Prioridade &prioridade)
{
    this->prioridade = prioridade;
}
void HistoriaDeUsuario::setEstado(const Estado &estado)
{
    this->estado = estado;
}
void HistoriaDeUsuario::setPessoa(const Pessoa &pessoa)
{
    this->pessoa = pessoa;
}
void HistoriaDeUsuario::setProjeto(const Projeto &projeto)
{
    this->projeto = projeto;
}
void HistoriaDeUsuario::setPlanoSprint(const PlanoSprint &planoSprint)
{
    this->planoSprint = planoSprint;
}

// Getters
Codigo HistoriaDeUsuario::getCodigo() const { return codigo; }
Texto HistoriaDeUsuario::getTitulo() const { return titulo; }
Texto HistoriaDeUsuario::getPapel() const { return papel; }
Texto HistoriaDeUsuario::getAcao() const { return acao; }
Texto HistoriaDeUsuario::getValor() const { return valor; }
Tempo HistoriaDeUsuario::getEstimativa() const { return estimativa; }
Prioridade HistoriaDeUsuario::getPrioridade() const { return prioridade; }
Estado HistoriaDeUsuario::getEstado() const { return estado; }
Pessoa HistoriaDeUsuario::getPessoa() const { return pessoa; }
Projeto HistoriaDeUsuario::getProjeto() const { return projeto; }
PlanoSprint HistoriaDeUsuario::getPlanoSprint() const { return planoSprint; }