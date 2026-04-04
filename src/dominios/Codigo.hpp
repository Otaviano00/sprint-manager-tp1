#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED

#include "Dominio.hpp"

class Codigo : public Dominio<std::string>
{
private:
    bool validar(string valor);
};

#endif // CODIGO_HPP_INCLUDED