#ifndef PESSOA_HPP_INCLUDED
#define PESSOA_HPP_INCLUDED

#include <dominios/Email.hpp>
#include <dominios/Nome.hpp>
#include <dominios/Senha.hpp>
#include <dominios/Papel.hpp>
#include <entidades/Entity.hpp>

#define TABLE_NAME "pessoa"

/**
 * @brief Classe que representa uma pessoa.
 *
 * Armazena as informações básicas do usuário do sistema.
 */
class Pessoa : public Entity
{
private:
    Email email; /**< E-mail da pessoa. */
    Nome nome;   /**< Nome da pessoa. */
    Senha senha; /**< Senha da pessoa. */
    Papel papel; /**< Papel da pessoa no sistema. */

public:
    Pessoa() : Entity(-1) {} // Set id inicial inválido
    Pessoa(long id) : Entity(id) {}

    /**
     * @brief Define o e-mail da pessoa.
     *
     * @param email Instância do domínio Email contendo o e-mail validado.
     */
    void setEmail(const Email &email);

    /**
     * @brief Retorna o e-mail da pessoa.
     *
     * @return Instância do domínio Email.
     */
    Email getEmail() const;

    /**
     * @brief Define o nome da pessoa.
     *
     * @param nome Instância do domínio Nome contendo o nome validado.
     */
    void setNome(const Nome &nome);

    /**
     * @brief Retorna o nome da pessoa.
     *
     * @return Instância do domínio Nome.
     */
    Nome getNome() const;

    /**
     * @brief Define a senha da pessoa.
     *
     * @param senha Instância do domínio Senha contendo a senha validada.
     */
    void setSenha(const Senha &senha);

    /**
     * @brief Retorna a senha da pessoa.
     *
     * @return Instância do domínio Senha.
     */
    Senha getSenha() const;

    /**
     * @brief Define o papel da pessoa.
     *
     * @param papel Instância do domínio Papel contendo o papel validado.
     */
    void setPapel(const Papel &papel);

    /**
     * @brief Retorna o papel da pessoa.
     *
     * @return Instância do domínio Papel.
     */
    Papel getPapel() const;
};

#endif