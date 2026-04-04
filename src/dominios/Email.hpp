#ifndef EMAIL_HPP_INCLUDED
#define EMAIL_HPP_INCLUDED

#include "Dominio.hpp"

class Email : public Dominio<std::string>
{
private:
    bool validar(string valor);
};

#endif // EMAIL_HPP_INCLUDED