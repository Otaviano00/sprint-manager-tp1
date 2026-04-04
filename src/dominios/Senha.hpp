#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED

#include "Dominio.hpp"

class Senha : public Dominio<std::string>
{
private:
    bool validar(string valor);
};

#endif // SENHA_HPP_INCLUDED