#ifndef PESSOA_HPP_INCLUDED
#define PESSOA_HPP_INCLUDED

#include "../dominios/dominios.hpp"

/**
    classe que representa uma pessoa
    armazena informações do usuário
*/

class Pessoa{
    private:
        Email email; // email da pessoa
        Nome nome; // nome da pessoa
        Senha senha; // senha da pessoa
    
    public:
        // define o email da pessoa
        void setEmail(const Email & email);
        // retorna o email da pessoa
        Email getEmail() const;
        //define o nome da pessoa
        void setNome(const Nome & nome);
        //retorna o nome da pessoa
        Nome getNome() const;
        //define a senha da pessoa
        void setSenha(const Senha & senha);
        //retorna a senha da pessoa
        Senha getSenha() const;
};

#endif