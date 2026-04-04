#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include "Dominio.hpp"

class Data : public Dominio<std::string>
{
private:
    bool validar(string valor);
};

#endif // DATA_HPP_INCLUDED