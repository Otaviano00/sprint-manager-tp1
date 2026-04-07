#include "Pessoa.hpp"

//define o email da pessoa
void Pessoa::setEmail(const Email & email){
        this->email = email;
}

//retorna o email da pessoa
Email Pessoa::getEmail() const{
    return email;
}
//define o nome da pessoa
void Pessoa::setNome(const Nome & nome){
        this->nome = nome;
}

//retorna o nome da pessoa
Nome Pessoa::getNome() const{
    return nome;
}
//define a senha da pessoa
void Pessoa::setSenha(const Senha & senha){
        this->senha = senha;
}

//retorna a senha da pessoa
Senha Pessoa::getSenha() const{
    return senha;
}
