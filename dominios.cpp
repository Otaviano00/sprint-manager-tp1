#ifndef DOMINIOS_CPP_INCLUDED
#define DOMINIOS_CPP_INCLUDED

#include "dominios.hpp"
#include "util.hpp"
#include <iostream>

// Código

bool Codigo::validar(string valor) {
    if (valor.length() != 5) {
        return false;
    }

    int numMaiusculos = 2;
    for (int i = 0; i < numMaiusculos; i++) {
        if ('A' > valor[i] || 'Z' < valor[i]) {
            return false;
        }
    }

    for (int i = numMaiusculos; i < valor.length(); i++) {
        if ('0' > valor[i] || '9' < valor[i]) {
            return false;
        }
    }

    return true;
}

// Data

bool Data::validar(string valor) {
    // Validação do formato
    if (valor.length() != 10) {
        return false;
    }

    if (valor[2] != '/' || valor[5] != '/') {
        return false;
    }

    // Validação dos dados
    int dia = std::stoi(valor.substr(0, 2));
    int mes = std::stoi(valor.substr(3, 2));
    int ano = std::stoi(valor.substr(6, 4));

    if (dia < 1 || dia > 31) {
        return false;
    }

    if (mes < 1 || mes > 12) {
        return false;
    }

    if (ano < 2000 || ano > 2999) {
        return false;
    }

    if (!util::validarData(dia, mes, ano)) {
        return false;
    }

    return true;
}

// Tempo

bool Tempo::validar(int valor) {
    if (valor < 1 || valor > 365) {
        return false;
    }
    return true;
}

// Nome

bool Nome::validar(string valor) {
    if (valor.empty() || valor.length() > 10) {
        return false;
    }

    for (int i = 0; i < valor.length(); i++) {
        char caracter = valor[i];
        if (!util::isChar(caracter, true) && !util::isIn(caracter, " ")) {
            return false;
        }

        if (util::isIn(caracter, " ") && !util::isChar(valor[i+1], true)) {
            return false;
        }
    }

    if (util::isIn(valor[0], " ") || util::isIn(valor[valor.length() - 1], " ")) {
        return false;
    }

    return true;
}

#endif // DOMINIOS_CPP_INCLUDED
