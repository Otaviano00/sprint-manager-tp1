#include "projeto.hpp"

Nome Projeto::getNome() const{
    return nome;
}

bool Projeto::setNome(const Nome & nome){
    if(!validar(nome)) return false;
    this->nome=nome;
    return true;
}

Codigo Projeto::getCodigo(){
    return codigo;
}

bool Projeto::setCodigo(const Codigo & codigo){
    if(!validar(codigo)) return false;
    this->codigo=codigo;
    return true;
}

Data Projeto::getInicio(){
    return inicio;
}

bool Projeto::setInicio(const Data & inicio){
    if(!validar(inicio)) return false;
    this->inicio=inicio;
    return true;
}

Data Projeto::getTermino(){
    return termino;
}

bool Projeto::setTermino(const Data & termino){
    if(!validar(termino)) return false;
    this->termino=termino;
    return true;
}