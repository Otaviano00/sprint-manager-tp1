#ifndef HISTORIAUSUARIO_HPP
#define HISTORIAUSUARIO_HPP

// Inclusao dos dominios utilizados pelos atributos da entidade
#include "dominios/Codigo.hpp"
#include "dominios/Texto.hpp"
#include "dominios/Tempo.hpp"
#include "dominios/Prioridade.hpp"
#include "dominios/Estado.hpp"

/// @brief Entidade que representa uma Historia de Usuario no sistema Scrum.
///
/// Cada historia e composta por papel (quem quer), acao (o que quer)
/// e valor (para que). Pode estar associada a um Projeto ou a um
/// Plano de Sprint, mas nunca a ambos simultaneamente (relacao OU).
class HistoriaUsuario {

private:
    // Chave primaria - identifica unicamente a historia (formato: 2 letras + 3 digitos)
    Codigo codigo;

    // Titulo descritivo da historia de usuario (ate 40 caracteres)
    Texto titulo;

    // Papel: quem deseja a funcionalidade (ex: "Como usuario...")
    Texto papel;

    // Acao: o que se deseja fazer (ex: "...quero poder...")
    Texto acao;

    // Valor: beneficio esperado (ex: "...para que eu possa...")
    Texto valor;

    // Estimativa de esforco em dias para completar a historia (1 a 365)
    Tempo estimativa;

    // Nivel de prioridade da historia: ALTA, MEDIA ou BAIXA
    Prioridade prioridade;

    // Estado atual da historia no fluxo Scrum: A_FAZER, FAZENDO ou FEITO
    Estado estado;

public:
    // -------------------------------------------------------
    // SETTERS - recebem objetos dominio ja validados
    // A validacao do formato ocorre dentro do proprio dominio,
    // entao aqui apenas atribuimos o valor recebido
    // -------------------------------------------------------

    /// @brief Define o codigo (chave primaria) da historia
    void setCodigo(const Codigo&);

    /// @brief Define o titulo da historia
    void setTitulo(const Texto&);

    /// @brief Define o papel (quem deseja a funcionalidade)
    void setPapel(const Texto&);

    /// @brief Define a acao (o que se deseja fazer)
    void setAcao(const Texto&);

    /// @brief Define o valor (beneficio esperado)
    void setValor(const Texto&);

    /// @brief Define a estimativa de esforco em dias
    void setEstimativa(const Tempo&);

    /// @brief Define a prioridade da historia
    void setPrioridade(const Prioridade&);

    /// @brief Define o estado atual da historia
    void setEstado(const Estado&);

    // -------------------------------------------------------
    // GETTERS - retornam copia do objeto dominio correspondente
    // -------------------------------------------------------

    /// @brief Retorna o codigo da historia
    Codigo getCodigo() const;

    /// @brief Retorna o titulo da historia
    Texto getTitulo() const;

    /// @brief Retorna o papel da historia
    Texto getPapel() const;

    /// @brief Retorna a acao da historia
    Texto getAcao() const;

    /// @brief Retorna o valor da historia
    Texto getValor() const;

    /// @brief Retorna a estimativa de esforco
    Tempo getEstimativa() const;

    /// @brief Retorna a prioridade da historia
    Prioridade getPrioridade() const;

    /// @brief Retorna o estado atual da historia
    Estado getEstado() const;
};

#endif // HISTORIAUSUARIO_HPP