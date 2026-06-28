#ifndef HISTORIADEUSUARIO_H
#define HISTORIADEUSUARIO_H

#include <string>
#include <dominios/Codigo.hpp>
#include <dominios/Texto.hpp>
#include <dominios/Tempo.hpp>
#include <dominios/Prioridade.hpp>
#include <dominios/Estado.hpp>
#include <core/Entity.hpp>
#include <modulos/pessoa/Pessoa.hpp>
#include <modulos/projeto/Projeto.hpp>
#include <modulos/plano_sprint/PlanoSprint.hpp>

/// @brief Entidade que representa uma Historia de Usuario no sistema Scrum.
///
/// Cada historia e composta por papel, acao e valor, e pode estar
/// associada a um Projeto ou a um Plano de Sprint (nunca ambos).
class HistoriaDeUsuario : public Entity
{
private:
    Codigo codigo;
    Texto titulo;
    Texto papel;
    Texto acao;
    Texto valor;
    Tempo estimativa;
    Prioridade prioridade;
    Estado estado;
    Pessoa pessoa;
    Projeto projeto;
    PlanoSprint planoSprint;

public:
    HistoriaDeUsuario() : Entity(0), pessoa(0), projeto(0), planoSprint(0) {}
    HistoriaDeUsuario(long id) : Entity(id), pessoa(0), projeto(0), planoSprint(0) {}

    // Setters
    void setCodigo(const Codigo &);
    void setTitulo(const Texto &);
    void setPapel(const Texto &);
    void setAcao(const Texto &);
    void setValor(const Texto &);
    void setEstimativa(const Tempo &);
    void setPrioridade(const Prioridade &);
    void setEstado(const Estado &);
    void setPessoa(const Pessoa &);
    void setProjeto(const Projeto &);
    void setPlanoSprint(const PlanoSprint &);

    // Getters
    Codigo getCodigo() const;
    Texto getTitulo() const;
    Texto getPapel() const;
    Texto getAcao() const;
    Texto getValor() const;
    Tempo getEstimativa() const;
    Prioridade getPrioridade() const;
    Estado getEstado() const;
    Pessoa getPessoa() const;
    Projeto getProjeto() const;
    PlanoSprint getPlanoSprint() const;
};

#endif