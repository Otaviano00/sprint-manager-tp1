#ifndef RECUPERARHISTORIACOMMAND_HPP
#define RECUPERARHISTORIACOMMAND_HPP

#include <modulos/historia_usuario/HistoriaDeUsuario.hpp>

class RecuperarHistoriaCommand
{
public:
    RecuperarHistoriaCommand() {}
    HistoriaDeUsuario getHistoriaFromInput();
};

#endif // RECUPERARHISTORIACOMMAND_HPP
