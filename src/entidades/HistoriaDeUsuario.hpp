#ifndef HISTORIADEUSUARIO_H
#define HISTORIADEUSUARIO_H

#include <string>
#include <dominios/Codigo.hpp>
#include <dominios/Texto.hpp>
#include <dominios/Tempo.hpp>
#include <dominios/Prioridade.hpp>
#include <dominios/Estado.hpp>

/// @brief Entidade que representa uma Historia de Usuario no sistema Scrum.
///
/// Cada historia e composta por papel, acao e valor, e pode estar
/// associada a um Projeto ou a um Plano de Sprint (nunca ambos).
class HistoriaDeUsuario {
private:
    Codigo codigo;
    Texto titulo;
    Texto papel;
    Texto acao;
    Texto valor;
    Tempo estimativa;
    Prioridade prioridade;
    Estado estado;

public:
    // Setters
    void setCodigo(const Codigo&);
    void setTitulo(const Texto&);
    void setPapel(const Texto&);
    void setAcao(const Texto&);
    void setValor(const Texto&);
    void setEstimativa(const Tempo&);
    void setPrioridade(const Prioridade&);
    void setEstado(const Estado&);

    // Getters
    Codigo getCodigo() const;
    Texto getTitulo() const;
    Texto getPapel() const;
    Texto getAcao() const;
    Texto getValor() const;
    Tempo getEstimativa() const;
    Prioridade getPrioridade() const;
    Estado getEstado() const;
};

#endif