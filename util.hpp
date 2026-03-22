#ifndef UTIL_CPP_INCLUDED
#define UTIL_CPP_INCLUDED

// Dominíos - Útil

enum Mes {
    JANEIRO = 1,
    FEVEREIRO = 2,
    MARCO = 3,
    ABRIL = 4,
    MAIO = 5,
    JUNHO = 6,
    JULHO = 7,
    AGOSTO = 8,
    SETEMBRO = 9,
    OUTUBRO = 10,
    NOVEMBRO = 11,
    DEZEMBRO = 12
};

namespace util {
    bool isAnoBissexto(int ano) {
        // if: ano é divisível por 4 e ano é divisível por 100 ou ano é divisível por 400, então ano é bissexto
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            return true;
        }
        return false;
    }

    // Não valida corretamente anos A.C
    bool validarData(int dia, int mes, int ano) {  
        if (dia < 1 || mes < 1 || ano < 1) {
            return false;
        }

        switch (static_cast<Mes>(mes)) {
            case Mes::FEVEREIRO:    
                return isAnoBissexto(ano) ? dia <= 29 : dia <= 28;

            case Mes::JANEIRO:
            case Mes::MARCO:
            case Mes::MAIO:
            case Mes::JULHO:
            case Mes::AGOSTO:
            case Mes::OUTUBRO:
            case Mes::DEZEMBRO:
                return dia <= 31;

            case Mes::ABRIL:
            case Mes::JUNHO:
            case Mes::SETEMBRO:
            case Mes::NOVEMBRO:
                return dia <= 30;
            default:
                return false;
        }
    }

    bool isChar(char caracter, bool includeCaps) {
        if (
            (caracter >= 'a' && caracter <= 'z') ||
            (
                includeCaps && 
                (caracter >= 'A' && caracter <= 'Z')
            )
        ) {
            return true;
        }

        return false;
    }

    bool isDigit(char caracter) {
        if (caracter - '0' >= 0 && caracter - '9' <= 9) {
            return true;
        }
        return false;
    }

    bool isIn(char caracter, string values) {
        for (char value : values) {
            if (caracter == value) {
                return true;
            }
        }
        return false;
    }

}

#endif // UTIL_CPP_INCLUDED