#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include<iostream>

using namespace std;
template <typename T>

class Dominio {
    protected:
        T valor;
        virtual bool validar(T valor) = 0;

    public:
        T getValor() const {
            return valor;
        }
        bool setValor(T valor) {
            if (!validar(valor)) {
                return false;
            }
            this->valor = valor;
            return true;
        }

};

class Codigo : public Dominio<std::string> {
    private:
        bool validar(string valor);

};

class Data : public Dominio<std::string> {
    private:
        bool validar(string valor);
};

class Email : public Dominio<std::string> {
    private:
        bool validar(string valor);
};

class Nome : public Dominio<std::string> {
    private:
        bool validar(string valor);
};

class Senha : public Dominio<std::string> {
    private:
        bool validar(string valor);
};

class Tempo : public Dominio<int> {
    private:
        bool validar(int valor);
};

class Texto : public Dominio<std::string> {
    private:
        bool validar(string valor);
};

enum Estado {
    A_FAZER,
    FAZENDO,
    FEITP
};

enum Papel {
    DESENVOLVEDOR,
    MESTRE_SCRUM,
    PROPRIETARIO_DE_PRODUTO
};

enum Prioridade {
    ALTA = 3,
    MEDIA = 2,
    BAIXA = 1
};

#endif // DOMINIOS_HPP_INCLUDED
