#ifndef IAUTENTICACAOSINGLETON_HPP
#define IAUTENTICACAOSINGLETON_HPP

#include <string>
#include <stdexcept>
#include <dominios/Papel.hpp>
#include <entidades/Pessoa.hpp>

class IAutenticacaoService
{
public:
    virtual bool autenticarLogin(std::string email, std::string senha) = 0;
    virtual PapelEnum getPapel() = 0;
};

#endif // IAUTENTICACAOSINGLETON_HPP
