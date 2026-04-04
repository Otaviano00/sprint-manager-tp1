#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED

#include "Dominio.hpp"

class Nome : public Dominio<std::string>
{
private:
    bool validar(string valor);
};

#endif // NOME_HPP_INCLUDED