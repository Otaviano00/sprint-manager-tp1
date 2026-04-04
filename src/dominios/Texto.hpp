#ifndef TEXTO_HPP_INCLUDED
#define TEXTO_HPP_INCLUDED

#include "Dominio.hpp"

class Texto : public Dominio<std::string>
{
private:
    bool validar(string valor);
};

#endif // TEXTO_HPP_INCLUDED