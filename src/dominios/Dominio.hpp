#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <iostream>
#include "../util/util.hpp"
#include "Estado.hpp"
#include "Papel.hpp"
#include "Propriedade.hpp"

using namespace std;
template <typename T>

class Dominio
{
protected:
    T valor;
    virtual bool validar(T valor) = 0;

public:
    T getValor() const
    {
        return valor;
    }
    bool setValor(T valor)
    {
        if (!validar(valor))
        {
            return false;
        }
        this->valor = valor;
        return true;
    }
};

#endif // DOMINIOS_HPP_INCLUDED
